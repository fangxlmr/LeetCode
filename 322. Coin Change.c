int twoMin(int x, int y)
{
    return x < y ? x : y;
}
int coinChange(int* coins, int coinsSize, int amount) {
    int i, j;
    int dp[amount + 1];

    for (i = 0; i <= amount; ++i) {
        dp[i] = INT_MAX - 1;
    }
    dp[0] = 0;
    for (i = 1; i <= amount; ++i) {
        for (j = 0; j < coinsSize; ++j) {
            if (coins[j] <= i) {
                dp[i] = twoMin(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
}