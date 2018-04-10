#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXSIZE 1000     /* 最大字符串长度 1000 */


/* 判断最长子回文字符串 */
char* longestPalindrome(char *);


int main()
{
    char *s = "ababd";
    printf("%d\n", strlen(s));
    printf("%s\n", s);
    printf("%s\n", longestPalindrome(s));
    return 0;
}


char* longestPalindrome(char* s) {
    int i, n = strlen(s);   /* n为字符串长度 */
    bool table[MAXSIZE][MAXSIZE] = {false};
    int left = 0, right = 0;

    /* 2种基础结果，写入二维表 */
    for(i = 0; i < n; ++i)
        table[i][i] = true;
    for(i = 0; i < n-1; ++i)
        if(s[i] == s[i+1]){
            table[i][i+1] = true;
            left = i;
            right = i+1;
        }
    /* 对窗口宽度大于等于3的序列进行检测,len为窗口宽度 */
    int len;
    for(len = 3; len <= n; ++len){  /* 对窗口宽度为 3 ~ n 的子串进行遍历 */
        for(i = 0; i < n-len+1; ++i){
            /* 以len 为窗口，在s上进行平移 ，判断是否符合地推条件 */
            int j = i+len-1;    /*这里的i, j分别为len窗口的左右标记 */
            if(s[i] == s[j] && table[i+1][j-1]){
                table[i][j] = true;
                left = i;
                right = j;
            }
        }
    }
    char *substr = (char *) malloc((right - left + 2) * (sizeof(char)));
    memset(substr, '\0', right - left + 2);
    int k, t = 0;
    for(k = left; k <= right; ++k)
        substr[t++] = s[k];
    return substr;
}