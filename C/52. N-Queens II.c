void nqueen (int n, int row, int *queen, int *count);
bool check (int row, int *queen);

int totalNQueens(int n) {
    int *queen = (int *) calloc (n, sizeof(int));
    int count = 0;
    /* 每个皇后的坐标为 (n, queen[n])*/
    nqueen (n, 0, queen, &count);
    return count;
}



/* 回朔法的核心函数*/
void nqueen (int n, int row, int *queen, int *count) {
    if (row == n){
        /* 循环完毕，保存结果*/
        ++(*count);
        return;
    }
    /* 将横坐标为row的皇后，从第一列到第N列，全部测试一遍*/
    for (int i = 0; i < n; ++i) {
        *(queen + row) = i;
        if (check(row, queen))  /* 判断当前位置时候合法*/
            nqueen(n, row + 1, queen, count);     /* 填写下一行皇后位置*/
    }
    return;
}


/* 检查(n, queen[n]) 皇后的合法性*/
bool check (int row, int *queen) {
    int i;
    for (i = 0; i < row; ++i) {     /*判断当前n皇后与之前的皇后是否同列，同对角线*/
        if (queen[row] == queen[i] || abs(queen[row] - queen[i]) == (row - i))
            return false;   /* 不合法*/
    }
    return true;
}
