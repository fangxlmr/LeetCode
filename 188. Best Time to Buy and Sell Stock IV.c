/* Approach 1: DP solution [Accepted] */
int twoMax(int x, int y)
{
    return x > y ? x : y;
}

int threeMax(int x, int y, int z)
{
    return twoMax(x, twoMax(y, z));
}

int maxProfit(int k, int* prices, int pricesSize) {
    int i, maxProfit;

    maxProfit = 0;
    /*
     * Situation 1.
     */
    if (pricesSize <= 0 || k <= 0) {
        return 0;

        /*
         * Situation 2: Optimize it if k is larger than pricesSize.
         * In this situation, we can do pricesSize times transaction
         * at the most to get the maxProfit. So we don't have to
         * maintain a 3D matrix as Situation 3 do. This will increase
         * the performance effectively.
         */
    } else if (k > pricesSize) {
        for (i = 0; i < pricesSize - 1; ++i) {
            if (prices[i] < prices[i + 1]) {
                maxProfit += prices[i + 1] - prices[i];
            }
        }
        return maxProfit;

        /*
         * Situation 3: We need to maintain a 3D matrix for dynamic programming.
         * In this situation, given k is less than pricesSize so than
         * dp is much more effective way to find the maxProfit.
         */
    } else {

        int t, x, y;
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
