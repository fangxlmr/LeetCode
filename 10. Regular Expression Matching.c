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
int memo[MAX][MAX];
int dp(char *s, int i, char *p, int j)
{
    int ans, first;

    if (memo[i][j] == -1) {
        if (!*(p + j)) {
            ans = !*(s + i);

        } else {
            first = *(s + i) && (*(s + i) == *(p + j) || *(p + j) == '.');
            if (*(p + j + 1) == '*') {
                ans = dp(s, i, p, j + 2) || first && dp(s, i + 1, p, j);

            } else {
                ans = first && dp(s, i + 1, p, j + 1);
            }
        }

        memo[i][j] = ans;
    }
    return memo[i][j];
}
bool isMatch(char* s, char* p) {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            memo[i][j] = -1;
        }
    }
    return dp(s, 0, p, 0);
}