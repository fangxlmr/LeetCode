#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAZSIZE 50

typedef char * ElemType;
typedef struct Node{    /* 栈结点结构 */
    ElemType s;
    struct Node *next;
}Node, *pNode;

typedef struct LinkStack{
    pNode top;  /* 栈顶 */
}LinkStack, *pStack;


const char *str_standard(char *, const char);
char *split(char *, const char);
bool push(pStack, ElemType);
bool pop(pStack);
char *simplifyPath(char *);

int main(){
    char *s = "/home/./";
    printf("%s\n", simplifyPath(s));

    return 0;
}



char* simplifyPath(char* path){
    if(!path)
        return path;
    int len = strlen(path);
    if(strcmp("/../", path)){
        return "/";
    }

    pStack Stack = (pStack) malloc(sizeof(LinkStack));   /* 新建栈 */
    Stack->top = NULL;
    char *sep = "/";    /* 分隔符 */
    char *s1 = ".", *s2 = "..";     /* 出栈 入栈条件 */

    char *pStr = split(path, *sep);  /* 将path以“/”分割 */
    int i = 0;  /* 字符指针数组的遍历变量 */
    while(pStr[i]){
        if(strcmp(pStr[i], s1))
            continue;
        else if(strcmp(pStr[i], s2))
            pop(Stack);
        else{
            push(Stack, pStr[i]);
        }
        ++i;    /* 指向下一个子串位置 */
    }

    char *result = (char *) calloc(len, sizeof(char));
    while(Stack->top){
        strrev(result);         /* 倒序 result */
        char p = Stack->top;   /* 出栈 */
        strrev(p);      /* 倒序 p */
        strcat(result, p);  /* 倒序拼接 */
        strcat(result, sep);    /* 倒序拼接分隔符"/" */
        strrev(result);     /* 正序回来 */

        pNode pDel = Stack->top;    /* 释放栈结点内存 */
        Stack->top = Stack->top->next;
        free(pDel);
    }

    return result;


}


/* 将串s以字符c分割，并返回字符数组  */
char *split(char *s, const char c){
    if(!s || s[0] == c){
        return NULL;
    }
    str_standard(s, c);    /* 把s的前后都补上字符c */

    int len = strlen(s);
    int *position[MAZSIZE];  /* 字符串中出现c的位置指针数组 */
    memset(position, 0, sizeof(position));

    /* 查找c在s中出现的位置，并存储到数组position中 */
    int i, j;
    for(i = 0, j = 0; i < len; i++){
        if(s[i] == c){
            position[j] = s + i;
            ++j;
        }
    }

    /* 将串s依照position分割，并将分割后的字符串存储进字符串指针数组中 */
    int pos_len = j - 1;    /* j个位置，最多j-1个子串*/
    char *pStr = (char *) calloc(pos_len, sizeof(char));  /* 字符数组长为pos_len */
    int p = 0;  /* 字符指针数组的变量 */

    for(j = 0, p = 0; j < pos_len-1; ++j, ++p){     /* 取出子串为一个新字符串，并将指针位置写入字符指针数组 */
        const int len = position[j+1] - position[j];
        if(len == 1){   /* 出现连续分隔符c的情况，直接跳过 */
            continue;
        }
        char *t = (char *) calloc(len, sizeof(char));        /* 新建子串 */
        strncpy(t, position[i]+1, len - 1);
        pStr[p] = t;
    }
    return pStr;    /* 返回值是字符指针数组的首地址 */
}


/* 将字符串开头和末尾都加上分隔符c */
const char *str_standard(char *s, const char c){
    int i = 0, len = strlen(s);
    const char *p = s;
    if(p[0] != c){  /* 开头不是字符c */
        char *t = (char *) calloc(2,  sizeof(char));
        t[0] = c;
        strrev(p);  /* 先倒序，在拼接到末尾，再倒序一次就OK */
        strcat(p, t);
        strrev(p);
        len += 1;   /* 多一个字符c，len长度需加一 */

        free(t);
        t = NULL;
    }
    if(p[len-1] != c){  /* 结尾不是字符c */
        char t[2] = {c};    /* 直接插入末尾 */
        strcat(p, t);
    }
    return p;
}



bool push(pStack Stack, ElemType s){
    pNode pNew = (pNode) malloc(sizeof(Node));
    pNew->s = s;

    /* 入栈 */
    pNew->next = Stack->top;
    Stack->top = pNew;

    return true;
}

bool pop(pStack Stack){
    if(Stack->top == NULL){
        printf("Stack is already empty...\n");
        exit(-1);
    }

    pNode pDel = Stack->top;
    Stack->top = Stack->top->next;

    free(pDel);
    pDel = NULL;

    return true;
}