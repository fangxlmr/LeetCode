/* The recursive solution works, but Time Limit Exceeded on LeetCode */
/*
int numTrees(int n) {
    if (n <= 1) {
        return 1;
    }

    int num = 0, i;
    for (i = 0; i < n; ++i) {
        num += numTrees(i) * numTrees(n - 1 - i);
    }
    return num;
}
*/

/* iteration solution */
int numTrees(int n) {
    if (n <= 0) {
        return 0;
    }

    int num[n + 1];
    memset (num, 0, sizeof(num));
    int i, j;
    num[0] = num[1] = 1;
    for (i = 2; i <= n; ++i) {
        for (j = 0; j < i; ++j){
            num[i] += num[j] * num[i - 1 - j];            
        }
    }
    return num[n];
}