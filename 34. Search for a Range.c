/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* Approach 1: Linear scan. */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *index, i;
    int left, right;

    *returnSize = 2;
    index = (int *) malloc(2 * sizeof(*index));
    index[0] = index[1] = -1;
    left = 0;
    right = numsSize - 1;

    for (i = 0; i < numsSize && left <= right; ++i) {
        if (nums[left] == target) {
            index[0] = left;
        } else {
            left++;
        }
        if (nums[right] == target) {
            index[1] = right;
        } else {
            right--;
        }
    }
    return index;
}

/* Approach 2.1: Binary search. */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *index, i;
    int low, mid, high;

    *returnSize = 2;
    index = (int *) malloc(2 * sizeof(*index));
    index[0] = index[1] = -1;
    low = 0;
    high = numsSize - 1;

    /* Find the first position. */
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (nums[mid] < target) {
            low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            if (mid == 0 || nums[mid - 1] < target) {
                index[0] = mid;
                break;
            } else {
                high = mid - 1;
            }
        }
    }
    /* Target is not in nums. */
    if (index[0] == -1) {
        return index;
    } else {
        /* Find the last position. */
        low = 0;
        high = numsSize - 1;
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                if (mid == numsSize - 1 || nums[mid + 1] > target) {
                    index[1] = mid;
                    break;
                } else {
                    low = mid + 1;
                }
            }
        }
    }
    return index;
}

/* Approach 2.2: Binary search with refactoring code. */
/*
 * Helper function will find the leftest position if
 * it exits while leftest is true. It will return the rightest
 * position if exists while leftest is false. It will return -1
 * if no find.
 */
int helper(int *nums, int numsSize, int target, int leftest)
{
    int low, mid, high;

    low = 0;
    high = numsSize - 1;

    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (nums[mid] < target) {
            low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            /* Find the leftest position. */
            if (leftest) {
                if (mid == 0 || nums[mid - 1] < target) {
                    return mid;
                } else {
                    high = mid - 1;
                }
                /* Find the rightest position. */
            } else {
                if (mid == numsSize - 1 || nums[mid + 1] > target) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            }
        }
    }
    return -1;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *index;

    *returnSize = 2;
    index = (int *) malloc(2 * sizeof(*index));
    index[0] = helper(nums, numsSize, target, 1);
    if (index[0] == -1) {
        index[1] = -1;
    } else {
        index[1] = helper(nums, numsSize, target, 0);
    }
    return index;
}

