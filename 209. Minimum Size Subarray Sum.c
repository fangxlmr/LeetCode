/* Approach 1: Using two pointers. */
int minSubArrayLen(int s, int* nums, int numsSize) {
    int left;
    int i, sum, min;

    left = 0;
    sum = 0;
    min = INT_MAX;
    for (i = 0; i < numsSize; ++i) {
        sum += nums[i];
        while (sum >= s) {
            min = (i - left + 1 < min) ? (i - left + 1) : min;
            sum -= nums[left++];
        }
    }
    return min == INT_MAX ? 0 : min;
}

/* By optimizing brute force, we can see how the algorithm be optimized
 * and implemented. See the thought in this process of optimization.
 *
 * It's a wonderful idea.
 * From: https://leetcode.com/problems/minimum-size-subarray-sum/solution/#
 */

/* Approach 2: Brute force. [Time limited exceed] */
int minSubArrayLen(int s, int* nums, int numsSize) {
    int i, j, k;
    int sum, min;

    sum = 0;
    min = INT_MAX;
    for (i = 0; i < numsSize; ++i) {
        for (j = i; j < numsSize; ++j) {
            sum = 0;
            for (k = i; k <= j; ++k) {
                sum += nums[k];
            }
            if (sum >= s) {
                min = (j - i + 1 < min) ? (j - i + 1) : min;
                break;
            }
        }
    }
    return min == INT_MAX ? 0 : min;
}

/* Approach 3: A better brute force. [Accepted] */
int minSubArrayLen(int s, int* nums, int numsSize) {
    int i, j;
    int sum, min;

    if (numsSize == 0) {
        return 0;
    } else {
        int sums[numsSize];
        min = INT_MAX;
        sums[0] = nums[0];
        for (i = 1; i < numsSize; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        for (i = 0; i < numsSize; ++i) {
            for (j = i; j < numsSize; ++j) {
                sum = sums[j] - sums[i] + nums[i];
                if (sum >= s) {
                    min = (j - i + 1 < min) ? (j - i + 1) : min;
                    break;
                }
            }
        }
        return min == INT_MAX ? 0 : min;
    }
}

/* Approach 4: Using binary search with O(NlogN) time. [Accepted] */
/* Find the first number which is not lower than target. */
int helper(int *v, int left, int right, int target)
{
    int low, mid, high;

    low = left;
    high = right;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (v[mid] < target) {
            low = mid + 1;
        } else {
            if (mid == left || v[mid - 1] < target) {
                return mid;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int minSubArrayLen(int s, int* nums, int numsSize) {
    int i, j, bound;
    int min;

    if (numsSize == 0) {
        return 0;
    } else {
        int sums[numsSize + 1];     /* A tricky here to have a numsSize + 1 size array. */
        min = INT_MAX;
        sums[0] = 0;
        for (i = 1; i <= numsSize; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];     /* A little diff with Approach 3. */
        }
        for (i = 1; i <= numsSize; ++i) {       /* A little diff with Approach 3. */
                bound = helper(sums, i, numsSize, s + sums[i - 1]);
                if (bound != -1) {
                    min = (bound - i + 1 < min) ? (bound - i + 1) : min;
                }
            }
        }
        return min == INT_MAX ? 0 : min;
}

