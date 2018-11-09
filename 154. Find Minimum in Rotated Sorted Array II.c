int findMin(int* nums, int numsSize) {
    int low, mid, high;

    low = 0;
    high = numsSize - 1;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if ((mid == 0 && nums[mid] < nums[mid + 1]) || 
            (mid == numsSize - 1 && nums[mid] < nums[mid - 1]) || 
            (nums[mid - 1] > nums[mid] && nums[mid] <= nums[mid + 1])) {
            return nums[mid];
        } else if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else if (nums[mid] < nums[high]) {
            high = mid - 1;
        } else {
            high--;
        }
    }
    return nums[mid];
}
