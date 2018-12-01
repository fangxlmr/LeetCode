int twoMax(int x, int y)
{
    return x > y ? x : y;
}

int threeMax(int x, int y, int z)
{
    return twoMax(x, twoMax(y, z));
}
int maxProfit(int k, int* prices, int pricesSize) {
    if (pricesSize <= 0 || k <= 0) {
        return 0;
    }

    int i, j, t;
    int x, y;
    int dp[2][2][k + 1], maxProfit;

    for (t = 0; t <= k; ++t) {
        dp[0][0][t] = 0;
        dp[0][1][t] = -prices[i];
    }
    dp[0][1][k] = INT_MIN;
    maxProfit = 0;
    for (i = 1; i < pricesSize; ++i) {
        x = i % 2;
        y = (i - 1) % 2;
        for (t = 0; t <= k; ++t) {
            dp[x][0][t] = twoMax(dp[y][0][t], (t != 0) ? (dp[y][1][t - 1] + prices[i]) : INT_MIN);
            dp[x][1][t] = twoMax(dp[y][1][t], dp[y][0][t] - prices[i]);
            maxProfit = threeMax(maxProfit, dp[x][0][t], dp[x][1][t]);
        }
    }
    return maxProfit;
}