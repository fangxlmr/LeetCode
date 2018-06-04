#define OFFSET 1000
static int M = 0;  /* 求余散列法的模数 */
typedef int ElemType;


/* 采用链接法解决冲突问题 */
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


/*
 * 创建 n 个槽的Hash表，成功返回hash表的HashTable型指针，并将散列法的模数设置为 n - 1.
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

int *twoSum(int *nums, int numsSize, int target)
{
    int i, min = nums[0];      //min是数组中的最小值
    int *indices = (int *)calloc(2, sizeof(int));
    for(i=0; i< numsSize; ++i)  //找出数组的最小值
    {
        if(nums[i] < min)
            min = nums[i];
    }
    int max = target - min, n = max - min + 1;  //max为满足max + min = target的最大值，n为哈希表长度
    M = n;
    HashTable hashtable = create_HashTabe(n);   //创建哈希表，长度为n
    for(i=0; i<numsSize; ++i){
        pNode node = search_HashTable(hashtable, target-nums[i]);   //采取边查找，边插入值的方式
        if(node){       //当出现符合要求的数值时，给输出数组赋值
            indices[0] = node->value;   //注意，这里的赋值语句的顺序
            indices[1] = i;
            destroy_HashTable(hashtable, node->value);
            break;
        }
        else{
            insert_HashTable(hashtable, nums[i], i);    //若没有满足的值，则插入进哈希表
        }
    }
    return indices;
}



/* 散列函数hash(key) */
int hash(ElemType key)
{
    return (key+OFFSET) % M;
}


/* 创建n个槽的哈希表 */
HashTable create_HashTabe(int n)
{
    if(n < 10)  /* hash表长必须大于10 */
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
    
    M = n;    /* 将模数修改为 n - 1 */
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
 * 在哈希表中插入数据
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
    /* 需要判断key相等，才算是找到了key值 */
    while(pCur && pCur->key != key){
        pPre = pCur;    /* 新结点的预备插入点 */
        pCur = pCur->next;
    }

    /* 如果key存在，不需要再次插入，返回false。保证不存在相同的key。 */
    if(pCur)
        return false;
    /* 否则，key不存在，为新结点分配空间 */
    pNode pNew = (pNode) malloc(sizeof(Node));
    if(!pNew)
    {
        printf("pNew malloc faild,program exit...");
        return false;
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
    /* 需要判断key相等，找到了匹配值 */
    while(pCur && pCur->key != key){
        pPre = pCur;
        pCur = pCur->next;
    }
    if(!pCur)   /* 哈希表中没有该键值对 */
        return false;

    /* 若 pCur 不为空，说明找到了匹配值，删除它，并返回true */
    if(pCur == hashtable[hash(key)].first)
        hashtable[hash(key)].first = NULL;
    else
        pPre->next = pCur->next;
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


