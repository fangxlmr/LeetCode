// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int low, mid, high;
    
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (isBadVersion(mid) && (mid == 0 || !isBadVersion(mid - 1))) {
            return mid;
        } else if (!isBadVersion(mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}