char* longestCommonPrefix(char** strs, int strsSize) {
    char *result;
    char *index;
    char c;
    int i, j;

    result = (char *) malloc(1000 * sizeof(char));
    result[0] = '\0';
    index = result;
    j = 0;

    if (strsSize <= 0 || strs[0] == NULL) {
        return result;
    }
    while ((c = strs[0][j]) != '\0') {
        for (i = 0; i < strsSize && strs[i][j] == c; ++i) {
            ;
        }
        if (i == strsSize) {
            *index++ = c;
            ++j;
        } else {
            break;
        }
    }

    *index = '\0';
    return result;
}