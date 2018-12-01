int twoMax(int x, int y)
{
    return x > y ? x : y;
}

int rob(int* nums, int numsSize) {
    int i, maxAmout;

    if (numsSize <= 0) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    } else {
        int dp[3];
        int x, y, z;

        dp[0] = nums[0];
        dp[1] = twoMax(nums[0], nums[1]);
        maxAmout = twoMax(dp[0], dp[1]);
        for (i = 2; i < numsSize; ++i) {
            x = i % 3;
            y = (i - 1) % 3;
            z = (i - 2) % 3;
            dp[x] = twoMax(dp[z] + nums[i], dp[y]);
            maxAmout = twoMax(maxAmout, dp[x]);
        }
        return maxAmout;
    }
}