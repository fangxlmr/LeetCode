/* recursion */
bool isMatch(char* s, char* p) {
    int first;

    if (!*p) {
        return !*s;
    }
    first = (*s) && (*s == *p || *p == '.');
    if (*(p + 1) == '*') {
        return isMatch(s, p + 2) || first && isMatch(s + 1, p);

    } else {
        return first && isMatch(s + 1, p + 1);;
    }
}

/* top-down variation using DP */
#define MAX 1024
int memo[MAX][MAX];     /* 初始化为0 */
int dp(char *s, int i, char *p, int j)
{
    int ans, first;

    if (memo[i][j] == 0) {
        if (!*(p + j)) {
            ans = !*(s + i) + 1;    /* 匹配为2，不匹配为1 */

        } else {
            first = *(s + i) && (*(s + i) == *(p + j) || *(p + j) == '.');
            if (*(p + j + 1) == '*') {
                ans = (dp(s, i, p, j + 2) || first && dp(s, i + 1, p, j)) + 1;

            } else {
                ans = (first && dp(s, i + 1, p, j + 1)) + 1;
            }
        }

        memo[i][j] = ans;
    }
    return memo[i][j] - 1;
}
bool isMatch(char* s, char* p) {
    /* Doing this for LeetCode, usually don't need it */
    memset(memo, 0, MAX * MAX * sizeof(int));
    return dp(s, 0, p, 0);
}

/* bottom-up variation using DP */
bool isMatch(char *s, char *p)
{
    int i, j;
    int len_s, len_p;
    int first;

    len_s = strlen(s);
    len_p = strlen(p);
    int memo[len_s + 1][len_p + 1];
    memset(memo, 0, (len_s + 1) * (len_p + 1) * sizeof(int));
    memo[len_s][len_p] = 1;

    for (i = len_s; i >= 0; --i) {
        for (j = len_p - 1; j >= 0; --j) {
            /*
             * 这里的i < len_s只在 i = len_s, j = len_p - 1时有用，
             * 避免下面else语句中memo[i+1][j+1]中的i + 1访问越界。
             */
            first = i < len_s && (*(s + i) == *(p + j) || *(p + j) == '.');

            if (*(p + j + 1) == '*') {
                memo[i][j] = memo[i][j + 2] || (first && memo[i + 1][j]);
            } else {
                memo[i][j] = first && memo[i + 1][j + 1];
            }
        }
    }

    return memo[0][0];
}