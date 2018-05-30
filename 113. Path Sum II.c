/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct TreeNode TreeNode;

int count = 0;

static void save (int *array, int index, int **res, int *column) {
    int *dump;

    dump = (int *) malloc(index * sizeof(int));
    memcpy(dump, array, index * sizeof(int));
    res[count] = dump;
    column[count] = index;
    ++count;
}

static void path_sum (TreeNode *root, int sum, int *array, int index, int *res, int *column) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right && root->val == sum) {
        array[index++] = root->val;
        save(array, index, res, column); /* 保存有效结果 */
        return;
    }
    array[index] = root->val;

    /* 回溯处理左右子树 */
    path_sum(root->left,  sum - root->val, array, index + 1, res, column);
    path_sum(root->right, sum - root->val, array, index + 1, res, column);
}



int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {
    int **res, *column;      /* 待返回的数组 */
    count  = 0;     /* 对应数组下标 */
    res    = (int **) malloc(1000 * sizeof(int *));
    column = (int *)  malloc(1000 * sizeof(int));

    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int array[1000], index = 0;    /* 用于存储临时结果的数组 */
    path_sum(root, sum, array, index, res, column);
    *columnSizes = column;
    *returnSize  = count;
    return res;
}