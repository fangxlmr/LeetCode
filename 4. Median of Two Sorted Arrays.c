double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size;
    int *pre, *mid;
    int *num;

    size = nums1Size + nums2Size;
    if (size == 0) {    /* 两个数组均为空 */
        return 0.0;
    } else if (size == nums1Size || size == nums2Size) {    /* 其中一个为空 */
        num = (size == nums1Size) ? nums1 : nums2;

        *mid  = &num[size / 2];
        pre = mid - 1;
    } else {          /* 都不为空 */
        int j = 0, k = 0;
        num = (nums1Size > nums2Size) ? nums1 : nums2;

        for (int i = 0; i <= size / 2; ++i) {
            pre = mid;
            if (j < nums1Size && k < nums2Size) {
                if (nums1[j] < nums2[k]) {
                    mid = &nums1[j++];
                } else {
                    mid = &nums2[k++];
                }
            } else {
                ++mid;
            }

        }
    }
    printf("size = %d\npre = %d, mid = %d\n", size, *pre, *mid);
    if (size % 2 == 1) {
        return *mid * 1.0;
    } else {
        return (*pre + *mid) / 2.0;
    }
}