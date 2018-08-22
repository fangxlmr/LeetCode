/* recursion 1.0: Time Limit Exceeded */
int dp(int m, int n, int i, int j)
{
    if (i == m || j == n) {
        return 1;
    }

    return dp(m , n, i + 1, j) + dp(m, n, i, j + 1);
}
int uniquePaths(int m, int n) {
    return dp(m - 1, n - 1, 0, 0);
}

/* recursion 2.0: cached intermediate data, AC */
#define MAX 100
int memo[MAX][MAX];
int dp(int m, int n, int i, int j)
{
    int box;

    if (memo[i][j] == -1) {
        if (i == m || j == n) {
            box = 1;
        } else {
            box = dp(m , n, i + 1, j) + dp(m, n, i, j + 1);
        }
        memo[i][j] = box;
    }

    return memo[i][j];
}
int uniquePaths(int m, int n) {
    int i, j;
    for (i = 0; i < MAX; ++i) {
        for (j = 0; j < MAX; ++j) {
            memo[i][j] = -1;
        }
    }
    return dp(m - 1, n - 1, 0, 0);
}

/* iteration */
int uniquePaths(int m, int n) {
    int i, j;
    int memo[m][n];
    int box;

    for (i = 0; i < m; ++i) {
        memo[i][n - 1] = 1;
    }
    for (j = 0; j < n; ++j) {
        memo[m - 1][j] = 1;
    }

    for (i = m - 2; i >= 0; --i) {
        for (j = n - 2; j >= 0; --j) {
            memo[i][j] = memo[i + 1][j] + memo[i][j + 1];
        }
    }

    return memo[0][0];
}