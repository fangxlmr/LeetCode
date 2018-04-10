/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/* 定义求余hash函数中的偏置值。 hash(key) = (key + OFFSET) % M 
 * M 为static。且：M = n, n 为hash表长度
 **/
#define OFFSET 1000

static int M = 0;  /* 求余散列法的模数 */

typedef int ElemType;


/* 采用链接发解决冲突问题 */
typedef struct Node     /* Node为链表节点的数据结构 */
{
    ElemType key;
    ElemType value;
    struct Node *next;
}Node, *pNode;


/* Hash表每个槽的数据结构 */
typedef struct Bucket
{
    pNode first;    /* 指向Bucket内链表的第一个节点 */
}Bucket, *HashTable;

static int set_module(int n);
static bool isprime(int n);

/*
 * 创建 n 个槽的Hash表，成功返回hash表的HashTable型指针，并将散列法的模数设置为 n.
 * n < 10时，将 n = 10
 * 不成功程序 打印"hashtable malloc faild,program exit..."
 * 再返回 NULL
 */
HashTable create_HashTabe(int);


/*
 * 在给定Hash表中查找数据
 * 成功返回该键值对的链表地址
 * 失败则返回 NULL
 */
pNode search_HashTable(HashTable, ElemType);


/*
 * 插入键值对到哈希表
 * 插入成功，返回true
 * hash表不存在，或键值对已存在，返回false
 * 若插入失败，打印"pNew malloc faild,program exit...",再返回false
 */
bool insert_HashTable(HashTable, ElemType, ElemType);


/* 
 * 从哈希表删除数据
 * 成功，则返回true
 * 若给定的hash表不存在，返回false
 */
bool delete_HashTable(HashTable, ElemType);


/*
 * 销毁哈希表
 * 若该 hash 表不存在，返回false
 * 若销毁成功，返回true
 */
void destroy_HashTable(HashTable, int);

int all_unique(char *, int, int);
int lengthOfLongestSubstring(char *);


int main()
{

    /*FILE *fp;
    fp = fopen("D:\\LeetCode\\3. test_string.txt" , "r");
    if(!fp){
        printf("The file can not be opened.\n");
        exit(-1);
    }

    fseek( fp , 0 , SEEK_END );
    int file_size;
    file_size = ftell( fp );

    char *s;
    fseek( fp , 0 , SEEK_SET);
    s =  (char *)malloc( file_size * sizeof( char ) );
    fread( s , file_size , sizeof(char) , fp);  //读取文件中的所有字符，并赋值给字符串
    fclose(fp);
*/
    char *s = "alouzxilkaxkufsu";
    // char *s = "aaaaa";
    int ans;
    ans = lengthOfLongestSubstring(s);
    printf("ans = %d\n", ans);
    return 0;
}


int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    if(!len)
        return 0;
    int left = 0, right = 1;    /* 滑动窗口的左右标记,左闭右开 */
    int width = right - left;     /* 滑动窗口的宽度*/
    HashTable hashtable = create_HashTabe(len);
    pNode pFlag;
    int ctr = 1;
    while(right < len + 1){
        printf("loop %d: checking %c...  ", ctr, *(s+right-1));
        printf("left = %d, right = %d, width = %d.\n",left, right, width);      
        ++ctr;
        pFlag = search_HashTable(hashtable, *(s+right-1));
        if( pFlag ){ /* 右窗口*(s+right-1) 在hashtable里 */
            /* 删除多余的字符 */
            printf("find %c, deleting it and insert the current %c\n", *(s+right-1), *(s+right-1));
            int i, t;
            t = pFlag->value;
            for(i = left; i <= t; ++i)
                delete_HashTable(hashtable, *(s+i));
            /*  让窗口左left标记右移至 flag +1.*/
            left = t+1;
            insert_HashTable(hashtable, *(s+right-1), right-1);
            printf("inserting the current %c\n", *(s+right-1));
            ++right;
        }
        else{
        /* 如果left - right范围内 没有 重复字符位置，查看窗口宽度，再right + 1。 */
            width = (width < right - left) ? (right - left) : width;
            printf("unable to find %c, inserting it.\n", *(s+right-1));
            insert_HashTable(hashtable, *(s+right-1), right-1);
            ++right;
        }
    }
    destroy_HashTable(hashtable, len);
    return width;
}




/* 散列函数hash(key) */
static int hash(ElemType key)
{
    return (key + OFFSET) % (M-1);
}

/* 判断素数 */
static bool isprime(int n)
{
    int i;  
    for (i = 2; i * i <= n; ++i) {  
        if (n % i == 0)
            return false;  
    }  
    return true; 
}

/* 取模数为不大于表长n的最大素数 */
static int set_module(int n)    
{
    while(--n)
    {
        if(isprime(n))
            break;
        else
            continue;
    }
    return n;
}

/* 创建n个槽的哈希表 */
HashTable create_HashTabe(int n)
{
    if(n < 10)  /* 保证hash表长度至少为10 */
        n = 10;
    int i;
    HashTable hashtable = (HashTable) malloc(n*sizeof(Bucket));
    if(!hashtable)
    {
        printf("hashtable malloc faild,program exit...");
        return NULL;
    }
    /* 将哈希表置空 */
    for(i=0;i<n;i++)
        hashtable[i].first = NULL;
    
    M = set_module(n);    /* 将模数选取为不大于表长n 的最大素数 */
    return hashtable;
}


/*
 * 在哈希表中查找 key - value对
 * 查找成功，返回在哈希表中的位置
 * 查找不成功，返回NULL
*/
pNode search_HashTable(HashTable hashtable, ElemType key)
{
    if(!hashtable)     /* 该hash 表不存在，返回NULL */
        return NULL;
    pNode pCur = hashtable[hash(key)].first;
    /* 需要判断key，相等，找到了匹配值 */
    while(pCur && pCur->key != key)
        pCur = pCur->next;
    return pCur;

}


/*
 * 在哈希表中插入key
 * 如果key存在，返回false
 * 如果不存在，则插入对应链表的最后并返回ture
 *  
 */
bool insert_HashTable(HashTable hashtable, ElemType key, ElemType value)
{
    if(!hashtable)     /* 该hash 表不存在，返回NULL */
        return false;

    pNode pCur = hashtable[hash(key)].first;
    pNode pPre = pCur;  /* 链表的末位，初始值与pCur相同 */
    /* 需要判断key相等，查看是否存在key值 */
    while(pCur && pCur->key != key){
        pPre = pCur;    /* 新结点的预备插入点 */
        pCur = pCur->next;
    }

    if(pCur != NULL)    /* 如果key已经存在，不需要再次插入，返回false */
        return false;
    /* 否则，key不存在，为新结点分配空间 */
    pNode pNew = (pNode) malloc(sizeof(Node));
    if(!pNew)
    {
        printf("pNew malloc faild,program exit...");
        exit(-1);
    }
    pNew->key = key;
    pNew->value = value;
    pNew->next = NULL;

      /* 将新结点插入到链表最后 */
    if(hashtable[hash(key)].first == NULL)  /* 当插入点为第一个点的情况 */
        hashtable[hash(key)].first = pNew;
    else
        pPre->next = pNew;  /* 插入点为第 n 点 (n>1) 的情况 */
    return true;
}


/*
 * 从哈希表中删除数据
 * 如果key不存在，则返回false
 * 若key存在，则删除key，且返回true
 */

bool delete_HashTable(HashTable hashtable, ElemType key)
{
    if(!hashtable)     /* 该hash 表不存在，返回false */
        return false;

    pNode pCur = hashtable[hash(key)].first;   /* 当前结点 */
    pNode pPre = pCur;   /* 存储被删结点的前一个结点，初始值与pCur相同 */

    if(pCur->key == key){    /* 被删结点是第一个结点 */
        hashtable[hash(key)].first = pCur->next;
    }
    else{   /* 被删结点不是第一个结点 */
        while(pCur && pCur->key != key){
            pPre = pCur;
            pCur = pCur->next;
        }
        pPre->next = pCur->next;
    }
    free(pCur);
    pCur = NULL;
    return true;
}


/* 销毁槽数为 n 的哈希表 */
void destroy_HashTable(HashTable hashtable, int n)
{
    if(!hashtable)     /* 该hash 表不存在，不需要删除 */
        return;

    int i;
    /* 先逐个链表释放 */
    for(i=0; i<n; ++i)
    {
        pNode pCur = hashtable[i].first;
        pNode pDel = NULL;
        while(pCur)
        {
            pDel = pCur;
            pCur = pCur->next;
            free(pDel);
            pDel = NULL;
        }
    }
    /* 最后释放哈希表 */
    free(hashtable);
    hashtable = NULL;
    return;
}