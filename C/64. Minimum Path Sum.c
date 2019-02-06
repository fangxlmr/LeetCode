#define MIN(x, y) ((x) < (y) ? (x) : (y))
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int m, n;
    m = gridRowSize;
    n = gridColSize;

    int i, j;
    int memo[m][n];
    int sum;

    sum = 0;
    for (i = m - 1; i >= 0; --i) {
        sum += grid[i][n - 1];
        memo[i][n - 1] = sum;
    }
    sum = 0;
    for (j = n - 1; j >= 0; --j) {
        sum += grid[m - 1][j];
        memo[m - 1][j] = sum;
    }

    sum = 0;
    for (i = m - 2; i >= 0; --i) {
        for (j = n - 2; j >= 0; --j) {
            memo[i][j] = MIN(memo[i + 1][j], memo[i][j + 1]) + grid[i][j];
        }
    }

    return memo[0][0];
}

#undef MIN