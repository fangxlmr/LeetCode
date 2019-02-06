/*
 * Approach 1: DP solution [Accepted]
 * This is simple version of 188 on LeetCode by redefine k = 2.
 */
int twoMax(int x, int y)
{
    return x > y ? x : y;
}

int threeMax(int x, int y, int z)
{
    return twoMax(x, twoMax(y, z));
}

int maxProfit(int* prices, int pricesSize) {
    int i, maxProfit;

    maxProfit = 0;
    /*
     * Situation 1.
     */
    if (pricesSize <= 0) {
        return 0;

    } else {
        int k;
        int t, x, y;
        k = 2;
        /*
         * Using sliding array trick to minimize space complexity.
         * Here, the first "2" means which day we are in. The second "2" means we have
         * a share of stock now or not, 0 stands for having no share of stock today and
         * 1 stands for have 1 share of stock today more specifically. The last "t" means
         * how many times transaction we have already made.
         */
        int dp[2][2][k + 1];

        for (t = 0; t <= k; ++t) {
            dp[0][0][t] = 0;
            dp[0][1][t] = -prices[0];
        }
        dp[0][1][k] = INT_MIN;
        maxProfit = 0;
        for (i = 1; i < pricesSize; ++i) {
            x = i % 2;
            y = (i - 1) % 2;
            for (t = 0; t <= k; ++t) {
                /*
                 * Functional equation is the most critical part here.
                 * Be attention on boundary condition in function 1.
                 */
                dp[x][0][t] = twoMax(dp[y][0][t], (t != 0) ? (dp[y][1][t - 1] + prices[i]) : INT_MIN); /* [1] */
                dp[x][1][t] = twoMax(dp[y][1][t], dp[y][0][t] - prices[i]);         /* [12] */
                maxProfit = threeMax(maxProfit, dp[x][0][t], dp[x][1][t]);
            }
        }
        return maxProfit;
    }
}