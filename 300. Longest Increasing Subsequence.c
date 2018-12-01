/* Approach 1: Linear scan with O(2^N) time. */
#define MAX(x, y) ((x) > (y) ? (x) : (y))
int lengthOfLIS(int* nums, int numsSize) {
    int longest, res;
    int last, i, j, k;

    res = 0;
    for (i = 0; i < numsSize; ++i) {
        last = nums[i];
        longest = 1;
        for (j = i - 1; j >= 0; j--) {
            if (nums[j] < last) {
                longest++;
                last = nums[j];
            }
        }
        last = nums[i];
        for (j = i + 1; j < numsSize; ++j) {
            if (nums[j] > last) {
                longest++;
                last = nums[j];
            }
        }
        res = MAX(res, longest);
    }
    return res;
}

#undef MAX

/* Approach 2: DP solution with O(N2) time. */
int twoMax(int x, int y)
{
    return x > y ? x : y;
}
int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return 0;
    }

    int i, j, dp[numsSize];
    int longest;

    for (i = 0; i < numsSize; ++i) {
        dp[i] = 1;
    }
    longest = dp[0] = 1;
    for (i = 1; i < numsSize; ++i) {
        for (j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = twoMax(dp[j] + 1, dp[i]);
            }
        }
        longest = twoMax(longest, dp[i]);
    }
    return longest;
}

/* Approach 3: Binary search with O(NlogN) time. */
int helper(int *v, int i, int j, int target)
{
    int low, mid, high;

    low = i;
    high = j;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (v[mid] < target) {
            low = mid + 1;
        } else {
            if (mid == 0 || v[mid - 1] < target) {
                return mid;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int lengthOfLIS(int *nums, int numsSize) {
    if (numsSize <= 0) {
        return 0;
    }

    int lis[numsSize];
    int i, count;
    for (i = 0; i < numsSize; ++i) {
        lis[i] = INT_MAX;
    }
    lis[0] = nums[0];
    count = 1;

    for (i = 1; i < numsSize; ++i) {
        int j = helper(lis, 0, count - 1, nums[i]);
        if (j == -1) {
            lis[count++] = nums[i];
        } else {
            lis[j] = nums[i];
        }
    }
    return count;
}
int lengthOfLIS(const int* p, int cnt) {

    int i;
    int max = 0;
    int *seq = malloc(cnt * sizeof(int));

    for(i = 0; i < cnt; ++i, ++p) {
        int j;

        for(j = max-1; j >= 0; --j) {
            if (seq[j] < *p) {
                break;
            }
        }
        if (++j == max) {
            seq[max++] = *p;
        }
        else {
            seq[j] = seq[j] < *p ? seq[j] : *p;
        }
    }
    free(seq);
    return max;
}