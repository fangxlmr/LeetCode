/*
 * Reproduced from LeetCode accepted solutions runtime distribution.
 * Link: https://leetcode.com/submissions/detail/193335115/
 */
int numDecodings(char* s) {
    size_t len = strlen(s);
    if (!s || len <= 0 || s[0] == '0') {
        return 0;
     } else {
        int i, ways[len];
        int x, y, z;
        char first[2], second[3];

        memset(ways, 0, len * sizeof(int));
        ways[0] = 1;
        x = 0;
        for (i = 1; i < len; ++i) {
            /*
             * If the current digit is not '0', add dp[i - 1]
             */
            if (s[i] >= '1') {
                ways[i] += ways[i - 1];
            }
            /* If the previous digit is 1 or 2, and in the second case the current digit
             * is less than or equal to 6, add dp[i - 2]
             */
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                ways[i] += i >= 2 ? ways[i - 2] : 1;
            }
        }
        return ways[len - 1];
    }
}
