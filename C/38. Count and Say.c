#define MAX_SIZE 10000

char* countAndSay(int n) {
    int ci, ni;
    int count;
    char c;
    char *clist, *nlist;

    clist = (char *) malloc(MAX_SIZE * sizeof(char));
    nlist = (char *) malloc(MAX_SIZE * sizeof(char));
    memcpy(clist, "1", 2 * sizeof(char));

    while (n != 1) {
        ci = ni = 0;
        while ((c = clist[ci++]) != '\0') {
            count = 1;
            while (c == clist[ci]) {
                ++ci;
                ++count;
            }
            nlist[ni++] = (char) (count + '0');
            nlist[ni++] = c;
        }

        --n;
        nlist[ni] = '\0';
        char *tmp;
        tmp = clist;
        clist = nlist;
        nlist = tmp;
    }

    free(nlist);
    return clist;
}
