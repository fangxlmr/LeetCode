int climbStairs(int n) {
    int i;
    int steps[n];

    if (n == 1 || n == 2) {
        return n;
    } else {
        steps[n - 1] = 1;
        steps[n - 2] = 2;

        for (i = n - 3; i >= 0; --i) {
            steps[i] = steps[i + 1] + steps[i + 2];
        }
    }
    return steps[0];
}