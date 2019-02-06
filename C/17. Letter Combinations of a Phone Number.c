/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct _String {
    char *str;
    int idx;
}String;

#define push(S, c) S->str[S->idx++] = c
#define pop(S) S->idx--

char *dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
char **ans;
int count;

void save(String *S)
{
    char *one;

    one = (char *) malloc((S->idx + 1) * sizeof(char));
    memcpy(one, S->str, S->idx);
    *(one + S->idx) = '\0';     /* append a extra '\0' at the end */
    *(ans + count++) = one;
}

void dfs(char *digits, int idx, String *tmp)
{
    int i, len;
    char *str;

    if (!*(digits + idx)) {
        save(tmp);
    } else {
        str = dict[digits[idx] - '2'];
        len = strlen(str);
        for (i = 0; i < len; ++i) {
            push(tmp, str[i]);
            dfs(digits, idx + 1, tmp);
            pop(tmp);
        }
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    int len;        /* digits字符串长度 */
    int total;     /* total，总共具有的可能性 */

    len = 0;
    total = 1;
    while (digits && digits[len] != '\0') {
        if (digits[len] == '7' || digits[len] == '9') {
            total *= 4;
        } else {
            total *= 3;
        }
        ++len;
    }

    if (total == 1) {
        total = 0;
        ans = NULL;
    } else {
        String S;
        S.idx = 0;
        S.str = (char *) malloc((len + 1) * sizeof(char));
        ans = (char **) malloc(total * sizeof(char *));
        count = 0;
        dfs(digits, 0, &S);
    }

    *returnSize = total;
    return ans;
}

#undef push
#undef pop