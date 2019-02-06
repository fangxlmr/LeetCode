#include <limits.h>
/* Approch 1: recursive solution. */
double myPow(double x, int n) {
    if (n == 0) {
        return 1;
    } else if (x == 0 || x == 1) {
        return x;
    }

    if (n < 0) {
        /* 
         * Handle a bug here:
         * if n == INT_MIN, then -MIN_MIN will overflow.
         */
        if (n < -INT_MAX) {
            n = -INT_MAX;
            return 1 / (myPow(x, -n) * x);
        } else {
            return 1 / myPow(x, -n);
        }
    }
    if (n % 2 == 0) {
        return myPow(x * x, n / 2);
    } else {
        return x * myPow(x, n - 1);
    }
}

/* Approach 2: bit manipulation. */
double myPow1(double x, int n) {
    double pow;

    pow = 1;
    if (n < 0) {
        /* Handle a overfow bug. */
        x = 1 / x;
        if (n == INT_MIN) {
            n = INT_MAX;
            pow *= x;
        } else {
            n = -n;
        }
    }

    while (n) {
        if (n & 1) {
            pow *= x;
        }
        x *= x;
        n >>= 1;
    }
    return pow;
}
