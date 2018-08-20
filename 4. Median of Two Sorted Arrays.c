double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *num[nums1Size + nums2Size];
    int *end1, *end2;
    int *cur1, *cur2;
    int idx;

    end1 = nums1 + nums1Size;
    end2 = nums2 + nums2Size;
    cur1 = nums1;
    cur2 = nums2;
    idx  = 0;

    while (cur1 < end1 && cur2 < end2) {
        if (*cur1 < *cur2) {
            num[idx++] = cur1++;

        } else {
            num[idx++] = cur2++;
        }
    }
    while (cur1 < end1) {
        num[idx++] = cur1++;
    }
    while (cur2 < end2) {
        num[idx++] = cur2++;
    }

    double ret;
    if (idx % 2 == 1) {     /* odd */
        ret = *num[idx / 2] * 1.0;
    } else {        /* even */
        ret = (*num[idx / 2 - 1] + *num[idx / 2]) / 2.0;
    }

    return ret;
}