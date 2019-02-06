/* Approach 1: Recursive dynamic programming.*/
int nrows, ncols;
int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int helper(int **v, int i, int j, int memo[][ncols])
{
    int cr, cd; /* cr: needed hp if go rightward; cd: needed hp if go downward.  */

    if (memo[i][j] != 0) {
        return memo[i][j];
    }
    if (i == nrows - 1 && j == ncols - 1) {  /* Reach the bottom-right corner. */
        memo[i][j] = v[i][j] > 0 ? 1 : -v[i][j] + 1;
    } else if (i == nrows - 1) {    /* Reach the rightest column. */
        cr = helper(v, i, j + 1, memo);
        memo[i][j] = max(1, cr - v[i][j]);
    } else if (j == ncols - 1) {    /* Reach the bottom row. */
        cd = helper(v, i + 1, j, memo);
        memo[i][j] = max(1, cd - v[i][j]);
    } else {
        cr = helper(v, i, j + 1, memo);
        cd = helper(v, i + 1, j, memo);
        memo[i][j] = max(1, min(cr, cd) - v[i][j]);
    }
    return memo[i][j];
}
int calculateMinimumHP(int** dungeon, int dungeonRowSize, int *dungeonColSizes) {
    nrows = dungeonRowSize;
    ncols = *dungeonColSizes;
    
    int memo[nrows][ncols];
    memset(memo, 0, nrows * ncols * sizeof(int));
    return helper(dungeon, 0, 0, memo);
}

/* Approach 2: Iterative dynamic programming with O(N2) space. */
int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int calculateMinimumHP(int** dungeon, int dungeonRowSize, int *dungeonColSizes) {
    int m = dungeonRowSize;
    int n = *dungeonColSizes;
    int dp[m + 1][n + 1];     /* Memoization. */
    int i, j;   /* i for rows' iteration while j for column's iteration. */

    for (j = 0; j <= n; ++j) {
        dp[m][j] = INT_MAX;
    }
    for (i = 0; i <= m; ++i) {
        dp[i][n] = INT_MAX;
    }
    dp[m][n - 1] = 1;
    dp[m - 1][n] = 1;

    for (i = m - 1; i >= 0; --i) {
        for (j = n - 1; j >= 0; --j) {
            dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);

        }
    }
    return dp[0][0];
}

/* Approach 3: Optimized iterative dynamic programming with O(N) space. */
int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}
int calculateMinimumHP(int** dungeon, int dungeonRowSize, int *dungeonColSizes) {
    int m = dungeonRowSize;
    int n = *dungeonColSizes;
    int i, j, dp[m + 1];

    for (i = 0; i <= m; ++i) {
        dp[i] = INT_MAX;
    }
    dp[m - 1] = 1;
    for (j = n - 1; j >= 0; --j) {
        for (i = m - 1; i >= 0; --i) {
            dp[i] = max(1, min(dp[i], dp[i + 1]) - dungeon[i][j]);
        }
    }
    return dp[0];
}
