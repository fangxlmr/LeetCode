int cmp(const void *x, const void *y)
{
    return *(int *)y - *(int *)x;
}
int hIndex(int* citations, int citationsSize) {
    int i;

    qsort(citations, citationsSize, sizeof(int), cmp);
    for (i = 0; i < citationsSize; ++i) {
        if (citations[i] <= i) {
            return i - 1;
        }
    }
    return citationsSize;
}