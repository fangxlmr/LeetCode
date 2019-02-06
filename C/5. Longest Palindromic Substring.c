/* Method 1: Straight forward DP */
char* longestPalindrome(char* s) {
    static const int maxSize = 1000;
    int p[maxSize][maxSize];
    int i, j, len;
    int left, right;

    len = strlen(s);
    left = right = 0;

    memset(p, 0, maxSize * maxSize * sizeof(int));
    for (i = 0; i < len; ++i) {
        p[i][i] = 1;
    }
    for (i = 0; i < len - 1; ++i) {
        if (s[i] == s[i + 1]) {
            p[i][i + 1] = 1;
            left = i;
            right = i + 1;
        }
    }

    int n;
    for(n = 3; n <= len; ++n){
        for(i = 0; i < len - n + 1; ++i){
            j = i + n - 1;
            if (s[i] == s[j] && p[i + 1][j - 1]) {
                p[i][j] = 1;
                left = i;
                right = j;
            }
        }
    }

    char *substr = (char *) malloc((right - left + 2) * (sizeof(char)));
    for(i = 0, j = left; j <= right; ++i, ++j) {
        substr[i] = s[j];
    }
    substr[i] = '\0';
    return substr;
}

/* Approach 2: More simple DP */
char* longestPalindrome(char* s) {
    static const int maxSize = 1000;
    int i, j, len;
    int p[maxSize][maxSize];
    int left, right;

    len = strlen(s);
    memset(p, 0, maxSize * maxSize * sizeof(int));
    left = right = 0;
    for (j = 0; j < len; ++j) {
        p[i][i] = 1;
        for (i = 0; i < j; ++i) {
            p[i][j] = (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]));
            if (p[i][j] && j - i > right - left) {
                left = i;
                right = j;
            }
        }
    }

    char *substr = (char *) malloc((right - left + 2) * (sizeof(char)));
    for(i = 0, j = left; j <= right; ++i, ++j) {
        substr[i] = s[j];
    }
    substr[i] = '\0';
    return substr;
}