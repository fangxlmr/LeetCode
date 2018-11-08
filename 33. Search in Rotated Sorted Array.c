int search(int* nums, int numsSize, int target) {
    int low, mid, high;

    low = 0;
    high = numsSize - 1;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            if (nums[low] <= nums[mid] && nums[mid] <= nums[high]) {
                high = mid - 1;
            } else {
                low += 1;
            }
        } else {
            if (nums[low] <= nums[mid] && nums[mid] <= nums[high]) {
                low = mid + 1;
            } else {
                high -= 1;
            }
        }
    }
    return -1;
}
