/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int cmp(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int **ret, *each;    /* ret 为二维数组，each为一维数组 */
    unsigned int size;       /* ret数组的长度 */
    int i, j;            /* i, j为固定数 */
    int left, right;    /* left right 为双指针 */
    int sum;    /* 临时和变量 */

    if (numsSize == 0) {
        return NULL;
    }

    size = pow(numsSize, 4) / 24;    /* 最多有 numsSize^4 / 24个可能 */
    ret = (int **) malloc(size * sizeof(int *));
    *returnSize = 0;

    qsort(nums, numsSize, sizeof(*nums), cmp);
    for (int i = 0; i < numsSize - 3; ++i) {
        sum = nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
        if (sum > target) {     /* 剪枝优化 */
            break;
        }
        if (i != 0 && nums[i] == nums[i - 1]) { /* 去掉重复项 */
            continue;
        }
        for (j = i + 1; j <= numsSize - 2; ++j) {    /* j位数固定 */
            sum = nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
            if (sum > target) {   /* 剪枝优化 */
                break;
            }
            if (j != i + 1 && nums[j] == nums[j - 1]) { /* 去掉重复项 */
                continue;
            }
            left = j + 1;       /* 双指针设定值 */
            right = numsSize - 1;
            while (left < right) {  /* 判断双指针对应的和是否为target */
                if (left != j + 1 && nums[left]  == nums[left - 1]) {   /* 去除重复项 */
                    ++left;
                    continue;
                }
                if (right != numsSize - 1 && nums[right] == nums[right + 1]) {
                    --right;
                    continue;
                }

                sum = nums[i] +nums[j] + nums[left] + nums[right];
                if (sum == target) {   /* 有效解，保存，继续下一个*/
                    each = (int *) malloc(4 * sizeof(int));
                    each[0] = nums[i];
                    each[1] = nums[j];
                    each[2] = nums[left];
                    each[3] = nums[right];
                    ret[(*returnSize)++] = each;
                    ++left;
                } else if (sum < target) {     /* 偏小，left右移 */
                    ++left;
                } else {        /* 偏大，right左移 */
                    --right;
                }
            }
        }
    }
    return ret;
}