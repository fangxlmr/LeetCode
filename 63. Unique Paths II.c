int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    /* simplify variable name */
    int m, n;
    int **grid;
    m = obstacleGridRowSize;
    n = obstacleGridColSize;
    grid = obstacleGrid;

    int memo[m][n];
    int i, j;

    /* initialization */
    memo[m - 1][n - 1] = !grid[m - 1][n - 1];
    for (i = m - 2; i >= 0; --i) {
        if (grid[i][n - 1] == 1) {
            memo[i][n - 1] = 0;
        } else {
            memo[i][n - 1] = memo[i + 1][n - 1];
        }

    }
    for (j = n - 2; j >= 0; --j) {
        if (grid[m - 1][j] == 1) {
            memo[m - 1][j] = 0;
        } else {
            memo[m - 1][j] = memo[m - 1][j + 1];
        }
    }

    int cur, down, right;
    for (i = m - 2; i >= 0; --i) {
        for (j = n - 2; j >= 0; --j) {
            cur  = grid[i][j];
            down = grid[i + 1][j];
            right = grid[i][j + 1];

            if (cur == 1) {
                memo[i][j] = 0;
            } else {
                if (down == 1 && right == 0) {
                    memo[i][j] = memo[i][j + 1];

                } else if (down == 0 && right == 1) {
                    memo[i][j] = memo[i + 1][j];

                } else if (down == 0 && right == 0) {
                    memo[i][j] = memo[i + 1][j] + memo[i][j + 1];

                } else {
                    memo[i][j] = 0;
                }
            }
        }
    }

    return memo[0][0];
}