/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int bisearch (int *nums, int target, int left, int right);
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *ret, index, begin, end;

    *returnSize = 2;
    ret = (int *) malloc(2 * sizeof(int));
    ret[0] = -1;
    ret[1] = -1;

    index = bisearch(nums, target, 0, numsSize - 1);
    if (index == -1) {   /* 没有对应元素 */
        return ret;
    }
    for (begin = index;  begin >= 0 ; --begin) { /* 向左查找 */
        if (nums[begin] != target) {
            break;
        }
    }
    ret[0] = begin + 1;
    for (end = index; end < numsSize; ++end) {  /* 向右查找 */
        if (nums[end] != target) {
            break;
        }
    }
    ret[1] = end - 1;
    return ret;
}

/* 二分查找 */
int bisearch (int *nums, int target, int left, int right) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;

    if (target == nums[mid]) {
        return mid;
    } else if (target < nums[mid]) {
        return bisearch(nums, target, left, mid - 1);
    } else {
        return bisearch(nums, target, mid + 1, right);
    }
}