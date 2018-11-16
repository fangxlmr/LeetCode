/* Approach 1: My original version of binary search. */
int hIndex(int* citations, int citationsSize) {
    int low, mid, high;

    low = 0;
    high = citationsSize - 1;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (citations[mid] < citationsSize - mid) {
            low = mid + 1;
        } else {
            if (mid == 0 || citations[mid - 1] <= citationsSize - mid) {
                return citationsSize - mid;
            } else {
                high = mid - 1;
            }
        }
    }
    return 0;
}

/* Approach 2: More clean version of binary search online. */
int hIndex(int* citations, int citationsSize) {
    int low, mid, high;

    low = 0;
    high = citationsSize - 1;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (citations[mid] == citationsSize - mid) {
            return citations[mid];
        } else if (citations[mid] > citationsSize - mid) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    /* This is more tricky part. */
    return citationsSize - low;
}
