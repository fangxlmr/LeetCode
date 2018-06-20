/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

//void quick_sort (int *nums, int left, int right);
int cmp(const void *a, const void *b)
{
    return (int *)a - (int *)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int **ret, *each;    /* ret 为二维数组，each为一维数组 */
    unsigned int size;       /* ret数组的长度 */
    int fix, left, right;    /* fix为第一个固定数， left right 为双指针 */
    int sum, target;    /* 临时和变量 */

    if (numsSize == 0) {
        return NULL;
    }

    size = pow(numsSize, 3) / 6;    /* 最多有 numsSize^3 / 6个可能 */
    ret = (int **) malloc(size * sizeof(int *));
    *returnSize = 0;

    qsort(nums, numsSize, sizeof(*nums), cmp);
    quick_sort(nums, 0, numsSize - 1);   /* 排序 */
    for (fix = 0; fix <= numsSize - 3; ++fix) {    /* fix第一位数 */
        if (nums[fix] > 0) {   /* 剪枝优化，第一个数大于0，后面不可能有有效解 */
            break;
        }

        /* 去掉重复项 */
        if (fix != 0 && nums[fix] == nums[fix - 1]) {
            continue;
        }
        target = 0 - nums[fix];       /* 另外两个数的和为 0 - fix */
        left = fix + 1;       /* 双指针设定值 */
        right = numsSize - 1;
        while (left < right) {  /* 判断双指针对应的和是否为target */
            if (left != fix + 1 && nums[left]  == nums[left - 1]) {   /* 去除重复项 */
                ++left;
                continue;
            }
            if (right != numsSize - 1 && nums[right] == nums[right + 1]) {
                --right;
                continue;
            }

            sum = nums[left] + nums[right];
            if (sum == target) {   /* 有效解，保存，继续下一个*/
                each = (int *) malloc(3 * sizeof(int));
                each[0] = nums[fix];
                each[1] = nums[left];
                each[2] = nums[right];
                ret[(*returnSize)++] = each;
                ++left;
            } else if (sum < target) {     /* 偏小，left右移 */
                ++left;
            } else {        /* 偏大，right左移 */
                --right;
            }
        }
    }
    return ret;
}

/*
static void swap(int *v, int x, int y)
{
    int temp;

    temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}


void quick_sort (int *v, int left, int right) {
    int i, last;

    if(left >= right) {
        return;
    }
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; ++i) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    quick_sort(v, left, last - 1);
    quick_sort(v, last + 1, right);
}
 */
