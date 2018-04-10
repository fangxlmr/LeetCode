/* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


/* 链表结点结构 */
typedef struct Node{
    char key;
    struct Node *next;
}Node, *pNode;

/* 头结点结构 */
typedef struct LinkList{
    int size;       /* 记录该条链表的长度 */
    pNode first;    /* 头结点的指针位置 */
    pNode pTail;    /* 尾结点的指针位置 */
}LinkList, *pLinkList;


/* 在pNode后插入新结点 */
bool put(pLinkList, char);


/* 将每个链表的字符链接成字符串 */
char *connect(pLinkList);


/* 生成回文数序列的函数*/
int palindro(int, int);


char* convert(char *, int);


int main()
{
    char *s = "yfxthwympskqcaibsnutkhtevylciznigkcohccywooaoychlycvfwbcuofepuowfqmouoor";
    printf("%d\n%s\n%s", strlen(s), s, convert(s, 44));
    return 0;
}

char* convert(char* s, int numRows) {
    pLinkList linklist[numRows]; /* 创建 numRows 列的数组，每一列链接一个链表 */
    /* 初始化链表 */ 
    int k;
    for(k = 0; k < numRows; ++k)
        linklist[k] = (pLinkList) calloc(1, sizeof(LinkList));

    /* zigzag型输入到链表中 */
    int i = 0, j = 0;
    while( *(s+i) ){
        put(linklist[j], *(s+i));
        ++i;
        j = palindro(i, numRows); /* j 在0 ~ numRows内循环变化 */
    }
    char *str;
    int len = strlen(s);
    if(len == 0)
        str = "";
    else{
        /* zigzag之后的字符串，与原字符串长度相同 */
        str = (char *) calloc(len+1, sizeof(char));  
        i = j = 0;   /* 循环变量清零 */
        for(j = 0; j < numRows; ++j){
        	char *substr = connect(linklist[j]);
            strcat(str, substr);
            free(substr);
        }
    }

    /* free链表 */
    /* 先free链表 */
    for(j = 0; j < numRows; ++j){
        pNode pCur = linklist[j]->first;
        pNode pDel = pCur;
        while(pCur != NULL){
            pDel = pCur;
            pCur = pCur->next;
            free(pDel);
        }
    }
    /* 在free linklist 数组 */
    for(j = 0; j < numRows; ++j)
        free(linklist[j]);

    return str;   
}

/* 在pCur插入新结点key，返回新的节点位置 */
bool put(pLinkList linklist, char key){
    /* 创建新结点 */
    pNode pNew = (pNode) malloc(sizeof(Node));
    if(!pNew){
        printf("pNew malloc failed. program exiting...\n");
        exit(-1);
    }
    pNew->key = key;
    pNew->next = NULL;
    /* 插入新结点 */
    if(linklist->first == NULL){    /* 插入的结点为第一结点 */
        linklist->first = pNew;
        linklist->pTail = pNew; /* 刷新 LinkList尾结点的位置 */
        ++linklist->size;   /* 链表长度加1 */
    }
    else{   /* 插入的结点不为第一结点*/
        linklist->pTail->next = pNew;
        linklist->pTail = pNew;    /* 刷新 LinkList尾结点的位置 */
        ++linklist->size;   /* 链表长度加1 */
    }
    return true;
}


/* 将每个链表的字符链接成字符串 */
char *connect(pLinkList linklist){
    /* 为新的字符串分配内存, linklist->size+1 为链表的长度 */
    char *s = (char *) calloc(linklist->size+1, sizeof(char));

    if(linklist->size == 0) /* 若链表为空，直接返回空字符串 */
        return s;
    /* 若链表不为空，字符串赋值后再返回 */
    pNode pCur = linklist->first;   /* 结点循环变量 */
    int i;
    for(i = 0; i < linklist->size; ++i){
        s[i] = pCur->key;
        pCur = pCur->next;
    }
    return s;

}


/* 用来生成回文数的函数 */
int palindro(int i, int n){ 
    if(n == 1)
        return 0;
    else if(i < 2*n-1)
        return (i <= n-1) ? (i) : (2*n-2-i);
    else{
        i = i % (2*n-2);
        return (i <= n-1) ? (i) : (2*n-2-i);
    }
}
