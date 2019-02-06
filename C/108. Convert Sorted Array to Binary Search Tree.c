/**
 * Definition for a binary tree node.
 * struct struct TreeNode {
 *     int val;
 *     struct struct TreeNode *left;
 *     struct struct TreeNode *right;
 * };
 */
struct TreeNode *convert(int *nums, int left, int right) {
    struct TreeNode *t;

    if (left > right) {
        t = NULL;
    }  else {
        int mid;

        t = (struct TreeNode *) malloc(sizeof(*t));
        if (t != NULL) {
            mid = left + ((right - left) >> 1);   /* left + (right - left) / 2 */
            t->val = *(nums + mid);
            t->left = convert(nums, left, mid - 1);
            t->right = convert(nums, mid + 1, right);
        } else {
            t = NULL;
        }
    }
    return t;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode *root;

    if (numsSize == 0) {
        root = NULL;
    } else {
        root = convert(nums, 0, numsSize - 1);
    }
    return root;
}