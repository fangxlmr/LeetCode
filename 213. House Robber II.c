int twoMax(int x, int y)
{
    return x > y ? x : y;
}

int threeMax(int a, int b, int c)
{
    return twoMax(a, twoMax(b, c));
}

int fourMax(int a, int b, int c, int d)
{
    return twoMax(twoMax(a, b), twoMax(c, d));
}

int rob(int* nums, int numsSize) {
    int i, maxAmout;

    if (numsSize <= 0) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    } else if (numsSize == 2) {
        return twoMax(nums[0], nums[1]);
    } else {
        /*
         * Use sliding array to minimize space and
         * employ the second index to identify if
         * the first house had been robbed.
         */
        int dp[3][2];
        int x, y, z;

        dp[0][0] = 0;
        dp[0][1] = nums[0];
        dp[1][0] = nums[1];
        dp[1][1] = nums[0];
        maxAmout = fourMax(dp[0][0], dp[0][1], dp[1][0], dp[1][1]);
        for (i = 2; i < numsSize - 1; ++i) {
            x = i % 3;
            y = (i - 1) % 3;
            z = (i - 2) % 3;
            dp[x][0] = twoMax(dp[z][0] + nums[i], dp[y][0]);
            dp[x][1] = twoMax(dp[z][1] + nums[i], dp[y][1]);
            maxAmout = threeMax(maxAmout, dp[x][0], dp[x][1]);
        }
        int n = numsSize;
        x = (n - 1) % 3;
        y = (n - 2) % 3;
        z = (n - 3) % 3;
        dp[x][0] = twoMax(dp[z][0] + nums[n - 1], nums[y]);
        dp[x][1] = dp[y][1];
        maxAmout = threeMax(maxAmout, dp[x][0], dp[x][1]);

        return maxAmout;
    }
}