/* Approach 1: DP with 2D array. */
int min(int x, int y)
{
    return x < y ? x : y;
}
int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int nrows = triangleRowSize, ncols = triangleColSizes[nrows - 1];
    int mem[nrows][ncols];
    int i, j;

    for (j = 0; j < ncols; ++j) {
        mem[nrows - 1][j] = triangle[nrows - 1][j];
    }
    for (i = nrows - 2; i >= 0; --i) {
        for (j = 0; j < triangleColSizes[i]; ++j) {
            mem[i][j] = min(mem[i + 1][j], mem[i + 1][j + 1]) + triangle[i][j];
        }
    }
    return mem[0][0];
}

/* Approach 2: DP with 1D array. */
int min(int x, int y)
{
    return x < y ? x : y;
}
int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int nrows = triangleRowSize;
    int ncols = triangleColSizes[nrows - 1];
    int mini[ncols];
    int i, j;

    for (j = 0; j < ncols; ++j) {
        mini[j] = triangle[nrows - 1][j];
    }
    for (i = nrows - 2; i >= 0; --i) {
        for (j = 0; j < triangleColSizes[i]; ++j) {
            mini[j] = min(mini[j], mini[j + 1]) + triangle[i][j];
        }
    }
    return mini[0];
}