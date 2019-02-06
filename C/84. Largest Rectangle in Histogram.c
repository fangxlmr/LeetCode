int twoMax(int x, int y)
{
    return x > y ? x : y;
}

int twoMin(int x, int y)
{
    return x < y ? x : y;
}

int largestRectangleArea(int* heights, int heightsSize) {
    int i, res;
    int dp[2][2];
    int x, y, min, count;

    if (heightsSize <= 0) {
        return 0;
    }
    res = dp[0][0] = heights[0];
    dp[0][1] = 1;
    for (i = 1; i < heightsSize; ++i) {
        x = i % 2;
        y = (i - 1) % 2;

        count = dp[y][1];
        min = twoMin(dp[y][0] / count, heights[i]);
        if ((count + 1) * min > heights[i]) {
            dp[x][0] = (count + 1) * min;
            dp[x][1] = count + 1;
        } else {
            dp[x][0] = heights[i];
            dp[x][1] = 1;
        }
        res = twoMax(dp[x][0], res);
    }
    return res;
}