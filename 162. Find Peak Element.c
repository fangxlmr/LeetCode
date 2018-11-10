/* Approach 1: Linear scan.  */
int findPeakElement(int* nums, int numsSize) {
    int i;

    for (i = 0; i < numsSize - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            return i;
        }
    }
    return numsSize - 1;
        
}

/* Approach 2: Binary search.  */
int findPeakElement(int* nums, int numsSize) {
    int low, mid, high;

    low = 0;
    high = numsSize - 1;
    while (low < high) {
        mid = low + ((high - low) >> 1);
        if (nums[mid] > nums[mid + 1]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low; /* Return high; is also acceptable.  */
}
