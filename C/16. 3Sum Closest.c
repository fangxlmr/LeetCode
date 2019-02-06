int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int fix, left, right;   /* 双指针 */
    int sum;    /* 临时和变量 */
    int closet; /* 最接近的结果 */

    qsort(nums, numsSize, sizeof(int), cmp);
    closet = nums[0] + nums[1] + nums[2];

    for (fix = 0; fix < numsSize; ++fix) {
        left = fix + 1;
        right = numsSize - 1;
        while (left < right) {  /* 双指针移动 */
            sum = nums[fix] + nums[left] + nums[right];
            if (abs(sum - target) < abs(closet - target)) {
                closet = sum;
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }
    return closet;
}