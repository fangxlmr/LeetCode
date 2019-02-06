/* http://blog.sina.com.cn/s/blog_b9285de20101gy6n.html */
#define max(x, y) ((x) > (y) ? (x) : (y))
int match(char *s1, int i, char *s2, int j, int k)
{
    int t;

    for (t = 0; t < k; ++t) {
        if (*(s1 + i + t) != *(s2 + j + t)) {
            return 0;
        }
    }
    return 1;
}
bool isScramble(char *s1, char *s2)
{
    int n;
    n = strlen(s1);
    int i, j, k, t;
    int memo[n][n][n + 1];

    memset(memo, 0, n * n * sizeof(int));
    for (i = n - 1; i >= 0; --i) {
        for (j = n - 1; j >= 0; --j) {
            for (k = 1; k <= n - max(i, j); ++k) {
                if (match(s1, i, s2, j, k) == 1) {
                    memo[i][j][k] = 1;
                } else {
                    for (t = 1; t < k; ++t) {
                        if (memo[i][j][t] && memo[i + t][j + t][k - t] ||
                        memo[i][j + k - t][t] && memo[i + t][j][k - t]) {
                            memo[i][j][k] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    return memo[0][0][n];
}

#undef max