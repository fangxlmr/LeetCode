/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().



 * 伪代码
 * 核心函数
    void nqueen (int n) {
        for (i = 1; i <= MAX; ++i){
          queen[n] = i; //将横坐标为n的皇后，从1到MAX列，循环一遍
          if (check(n)) {   //判断是否位置是否合法
            if (n == MAX)
                printf the result;
            else
                nqueen(n + 1);  // 继续摆放下一个皇后
          }
        }
    }

 **/
#define DEBUG 1
#if DEBUG
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
#endif

#define MAX 200

void nqueen (int, int *);
void save (int *);
bool check (int, int *);
char ***output (int);
char *line (int, int);
char ***solveNQueens(int, int *);

int count = 0;
int N = 0;      /* 行/列数，N * N的方格  */
int *result[MAX];  /* 预分配MAX个字节的结果 */

#if DEBUG
int main (){
    int tmp, *returnSize = &tmp;
    *returnSize = 3;
    int n = 4;
    printf("here\n");
    char ***result = solveNQueens (n, returnSize);
    int i, j;
    for (i = 0; i < *returnSize; ++i) {
        for (j = 0; j < n; ++j){
            printf("%s\n", *(result[i] + j));
        }
        printf("\n");
    }

}
#endif

char*** solveNQueens(int n, int* returnSize) {
    int *queen = (int *) malloc (n * sizeof(int));
/* 每个皇后的坐标为 (n, queen[n])*/

    memset (queen, 0, sizeof(queen));
    N = n;
    nqueen (0, queen);
    *returnSize = count;
    return output (n);
}



/* 回朔法的核心函数*/

void nqueen (int row, int *queen) {
    int i;
    if (row == N){
/* 循环完毕，保存结果*/

        int *ans = (int *) malloc (N * sizeof(int));
        memcpy(ans, queen, N * sizeof(int));
        save(ans);
        return;
    }
    /* 将横坐标为row的皇后，从第一列到第N列，全部测试一遍*/
    for (i = 0; i < N; ++i) {
        *(queen + row) = i;
        if (check(row, queen))  /* 判断当前位置时候合法*/
            nqueen(row + 1, queen);     /* 填写下一行皇后位置*/

    }
}


/* 将合法结果保存到result中*/
void save (int *ans) {
    result[count]= ans;
    ++count; /* 下一个空闲位置*/
    return;
}


/* 检查(n, queen[n]) 皇后的合法性*/
bool check (int row, int *queen) {
    int i;
    for (i = 0; i < row; ++i) {     /*判断当前n皇后与之前的皇后是否  同列，同对角线*/
        if (queen[row] == queen[i] || abs(queen[row] - queen[i]) == (row - i))
            return false;   /* 不合法*/

    }
    return true;
}


/* 打印出合法结果, n列*/
char ***output (int n) {
/* 有效解集合对应的数组为 matrix*/
    char ***matrix = NULL;
    if (count == 0) {
        matrix = (char ***) calloc (1, sizeof(char **));
        matrix[0] = (char **) calloc(1, sizeof(char *));
        return matrix;
    }
    else {
        matrix =  (char ***) calloc (count, sizeof(char **));
        int i, j;
        for (i = 0; i < count; ++i) {   /* 遍历 result数组*/

            /* 每个有效解对应的矩阵为each_matrix*/
            char **each_matrix = (char **) calloc (n, sizeof(char *));
            for (j = 0; j < n; ++j) {
            /*输出每行的值*/
                *(each_matrix + j) = line (n, *(result[i] + j));
            }
            *(matrix + i) = each_matrix;
        }
    }
    return matrix;
}


/* n个位的字符串，第i位为Q，其余为dot "."*/
char *line (int n, int i) {
    char *str = (char *) calloc ((n + 1), sizeof(char));
    int j;
    for (j = 0; j < n; ++j)
        *(str + j) = '.';
    *(str + i) = 'Q';
    return str;
}
