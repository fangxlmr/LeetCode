int majorityElement(int* nums, int numsSize) {
    int i, major, count;

    count = 0;
    for (i = 0; i < numsSize; ++i) {
        if (count == 0) {
            ++count;
            major = nums[i];
        } else if (major == nums[i]) {
            ++count;
        } else {
            --count;
        }
    }

    return major;
}