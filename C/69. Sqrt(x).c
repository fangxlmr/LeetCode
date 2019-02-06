/* Approach 1: Binary search. */
int mySqrt(int x) {
    int low, mid, high;

    if (x > 1) {
        low = 0;
        high = x / 2 + 1;
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            if (mid == x / mid) {
                return mid;
            } else if (mid > x / mid) {
                high = mid - 1;
            } else {
                if ((mid + 1) > x / (mid + 1)) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            }
        }
    }
    /* Return 0 (or 1) if x = 0 (or 1),
     * otherwise this statement will not be reached.
     */
    return x;
}

/* Approach 2: Newton's method.
 * Reference: http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html
 */
int mySqrt(int x) {
    double last = 0;
    double res = 1;

    if (x == 0) {
        return 0;
    }
    while (abs(res - last) >= 1) {
        last = res;
        res = (res + x / res) / 2;
    }
    return (int) res;
}