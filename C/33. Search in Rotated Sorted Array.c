int search(int* nums, int numsSize, int target) {
    int low, mid, high;

    low = 0;
    high = numsSize - 1;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > nums[high]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}
