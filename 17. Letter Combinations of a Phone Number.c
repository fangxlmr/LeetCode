/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

char *dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void helper(char **result, int i, char *s, int len, int j)
{
    char *t;

    if (j == len) {
        return;
    } else {

        t = (char *) malloc(sizeof(char));
        for (int k = 0; k < len(dict[s[k] - '2']); ++k) {
            t[]
        }
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    char **result;
    char *str;
    int len;        /* digits字符串长度 */
    int i, num;     /* num，总共具有的可能性 */

    i = 0;
    num = 1;
    while (digits[i] != '\0') {
        if (digits[i] == '7' || digits[i] == '9') {
            num *= 4;
        } else {
            num *= 3;
        }
        ++i;
    }
    len = i;

    if (num == 1) {
        *returnSize = 0;
        return NULL;

    } else {
        *returnSize = num;
        result = (char **) malloc(num * sizeof(char *));


    }

    return result;
}
