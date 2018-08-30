/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int m, n, cm, cn;
    int *res, i;

    m = n = 0;
    cm = cn = 0;
    for (i = 0; i < numsSize; ++i) {
        if (m == nums[i]) {
            ++cm;
        } else if (n == nums[i]) {
            ++cn;
        } else if (cm == 0) {
            m = nums[i];
            ++cm;
        } else if (cn == 0) {
            n = nums[i];
            ++cn;
        } else {
            --cm;
            --cn;
        }
    }
    
    cm = cn = 0;
    for (i = 0; i < numsSize; ++i) {
        if (nums[i] == m) {
            ++cm;
        } else if (nums[i] == n) {
            ++cn;
        }
    }

    int idx = 0;
    res = (int *) malloc(2 * sizeof(int));
    if (cm > numsSize / 3) {
        res[idx++] = m;
    }
    if (cn > numsSize / 3) {
        res[idx++] = n;
    }
    *returnSize = idx;

    return res;
}