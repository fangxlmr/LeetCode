/* Approach 1: Simplest DP solution comes from JiKeShiJian E47. */
int twoMax(int x, int y)
{
    return x > y ? x : y;
}

int threeMax(int x, int y, int z)
{
    return twoMax(x, twoMax(y, z));
}

int threeMin(int x, int y, int z)
{
    int t;
    t = x < y ? x : y;
    t = t < z ? t : z;
    return t;
}

int maxProduct(int* nums, int numsSize) {
    int dp[2][2];
    int i, x, y, res;

    res = dp[0][0] = dp[0][1] = nums[0];
    for (i = 1; i < numsSize; ++i) {
        x = i % 2;
        y = (i - 1) % 2;
        dp[x][0] = threeMax(dp[y][0] * nums[i], dp[y][1] * nums[i], nums[i]);
        dp[x][1] = threeMin(dp[y][0] * nums[i], dp[y][1] * nums[i], nums[i]);
        res = twoMax(res, dp[x][0]);
    }
    return res;
}