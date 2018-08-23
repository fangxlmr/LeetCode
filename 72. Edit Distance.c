/* recursion: Time Limit Exceeded */
#define MIN(x, y) ((x) < (y) ? (x) : (y))
int minDistance(char *word1, char *word2) {
    int ans;
    int i = 0;
    char *word;

    if (!*word1 && !*word2) {   /* meet end at the same time */
        ans = 0;

    } else if (!*word1 || !*word2) {   /* word1 or word2 meet end first */
        word = *word1 ? word1 : word2;
        while (*(word + i)) {   /* the rest of string should be delete */
            ++i;
        }
        ans = i;

    } else if (*word1 == *word2) {
        ans = minDistance(word1 + 1, word2 + 1); /* match a single char */

    } else {
        int x, y, z;
        x = minDistance(word1, word2 + 1);      /* insert */
        y = minDistance(word1 + 1, word2);      /* delete */
        z = minDistance(word1 + 1, word2 + 1);  /* replace */
        ans = MIN(x, MIN(y, z)) + 1;
    }

    return ans;
}

#undef MIN


/*
 * recursion 2.0: cached intermediate ans.
 * ACCEPT on LeetCode for 1156 ms.
 * Not so good.
 */
#define MAX 1024
#define MIN(x, y) ((x) < (y) ? (x) : (y))
int memo[MAX][MAX];

int helper(char *w1, int i, char *w2, int j)
{
    int ans;
    char *w;

    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    if (!*(w1 + i) && !*(w2 + j)) {
        ans = 0;

    } else if (!*(w1 + i) || !*(w2 + j)) {
        ans = 0;
        w = *(w1 + i) ? w1 + i : w2 + j;
        while (*w++) {
            ++ans;
        }

    } else if (*(w1 + i) == *(w2 + j)) {
        ans = helper(w1, i + 1, w2, j + 1);

    } else {
        int x, y, z;
        x = helper(w1, i, w2, j + 1);      /* insert */
        y = helper(w1, i + 1, w2, j);      /* delete */
        z = helper(w1, i + 1, w2, j + 1);  /* replace */
        ans = MIN(x, MIN(y, z)) + 1;
    }
    memo[i][j] = ans;

    return memo[i][j];
}

int minDistance(char *word1, char *word2) {
    int i, j;

    for (i = 0; i < MAX; ++i) {
        for (j = 0; j < MAX; ++j) {
            memo[i][j] = -1;
        }
    }

    return helper(word1, 0, word2, 0);
}

#undef MIN
#undef MAX

/* iteration version: ac on LeetCode for 4 ms */
#define MIN(x, y) ((x) < (y) ? (x) : (y))
int minDistance(char *word1, char *word2)
{
    int len1, len2;
    len1 = strlen(word1);
    len2 = strlen(word2);

    int i, j;
    int memo[len1 + 1][len2 + 1];
    memo[len1][len2] = 0;
    for (i = 0; i < len1; ++i) {
        memo[i][len2] = len1 - i;
    }
    for (j = 0; j < len2; ++j) {
        memo[len1][j] = len2 - j;
    }

    int x, y, z;
    for (i = len1 - 1; i >= 0; --i) {
        for (j = len2 - 1; j >= 0; --j) {
            if (*(word1 + i) == *(word2 + j)) {
                memo[i][j] = memo[i + 1][j + 1];
            } else {
                x = memo[i][j + 1];     /* insert */
                y = memo[i + 1][j];     /* delete */
                z = memo[i + 1][j + 1]; /* replace */
                memo[i][j] = MIN(x, MIN(y, z)) + 1;
            }
        }
    }

    return memo[0][0];
}

#undef MIN