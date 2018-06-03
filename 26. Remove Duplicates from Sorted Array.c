int removeDuplicates(int* nums, int numsSize) {
    int *left, *right;

    left = right = nums;
    if (numsSize == 0) {
        return 0;
    }
    for (int i = 0; i < numsSize; ++i) {
        if (*right == *left) {
            ++right;
        } else {
            *(++left) = *(right++);
        }
    }
    return (left - nums + 1);
}