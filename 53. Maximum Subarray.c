/* kind of like a DP */
#define max(x, y) ((x) > (y) ? (x) : (y))
int maxSubArray(int* nums, int numsSize) {
    int i;
    int res, cur_sum;

    res = INT_MIN;
    cur_sum = 0;

    for (i = 0; i < numsSize; ++i) {
        cur_sum = max(cur_sum + nums[i], nums[i]);
        res = max(cur_sum, res);
    }

    return res;
}

/* using Divide and Conquer */
#define max(x, y) ((x) > (y) ? (x) : (y))
int helper(int *v, int left, int right);
int maxSubArray(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    return helper(nums, 0, numsSize - 1);
}

int helper(int *v, int left, int right)
{
    int mid;
    int t;
    int lmax, rmax, mmax;

    if (left >= right) {
        return v[left];
    }
    mid = left + (right - left) / 2;
    lmax = helper(v, left, mid - 1);
    rmax = helper(v, mid + 1, right);
    mmax = v[mid];
    t = mmax;

    for (int i = mid - 1; i >= left; --i) {
        t += v[i];
        mmax = max(t, mmax);
    }
    t = mmax;
    for (int i = mid + 1; i <= right; ++i) {
        t += v[i];
        mmax = max(t, mmax);
    }

    return max(mmax, max(lmax, rmax));
}