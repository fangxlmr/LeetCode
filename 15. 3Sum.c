/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quick_sort (int *nums, int left, int right);
int** threeSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    if (numsSize == 0) {
        return NULL;
    }

    /* 定义变量 */
    int **ret, *each;    /* ret 为二维数组，each为一维数组 */
    unsigned int size;       /* ret数组的长度 */
    int fix, left, right;    /* fix为第一个固定数， left right 为双指针 */
    int sum, target;    /* 临时和变量 */

    /* 变量初始化 */
    size = pow(numsSize, 3) / 6;    /* 最多有 numsSize^3 / 6个可能 */
    printf("size = %d\n", size);
    ret = (int **) malloc(size * sizeof(int *));
    *returnSize = 0;

    quick_sort(nums, 0, numsSize - 1);   /* 排序 */
    for (fix = 0; fix <= numsSize - 3; ++fix) {    /* fix第一位数 */
        if (nums[fix] > 0) {   /* 剪枝优化，第一个数大于0，后面不可能有有效解 */
            break;
        }

        /* 去掉重复项 */
        if (fix != 0 && nums[fix] == nums[fix - 1]) {
            continue;
        }
        target = 0 - nums[fix];       /* 另外两个数的为 0 - fix */
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
                /* 保存有效解 */
                ret[*returnSize] = each;
                (*returnSize)++;
                /* 继续下移 */
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


/* 快速排序 */
void quick_sort (int *nums, int left, int right) {
    if (left > right) {
        return;
    }

    int i, j, pivot, tmp;

    i = left;
    j = right;
    pivot = nums[left];
    while (i < j) {
        while (nums[j] >= pivot && i < j) {
            --j;
        }
        while (nums[i] <= pivot && i < j) {
            ++i;
        }
        if (i < j) {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
    nums[left] = nums[i];
    nums[i] = pivot;

    quick_sort(nums, left,  i - 1);
    quick_sort(nums, i + 1, right);
}