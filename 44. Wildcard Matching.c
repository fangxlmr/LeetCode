bool isMatch(char* s, char* p) {
    int len_s, len_p;
    len_s = strlen(s);
    len_p = strlen(p);

    int i, j;
    int first;
    int memo[len_s + 1][len_p + 1];

    memset(memo, 0, (len_s + 1) * (len_p + 1) * sizeof(int));
    memo[len_s][len_p] = 1;
    for (i = len_s; i >= 0; --i) {
        for (j = len_p - 1; j >= 0; --j) {
            if (*(p + j) == '*') {
                memo[i][j] = memo[i][j + 1] || ((i < len_s) && memo[i + 1][j]);

            } else {
                first = *(s + i) == *(p + j) || *(p + j) == '?';
                memo[i][j] = first && ((i < len_s) && memo[i + 1][j + 1]);
            }
        }
    }

    return memo[0][0];
}