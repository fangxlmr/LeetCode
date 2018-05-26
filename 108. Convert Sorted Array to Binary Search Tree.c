/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;
TreeNode *sorted_array_to_BST(int *nums, int left, int right) {
    TreeNode *t = (TreeNode *) malloc(sizeof(struct TreeNode));

    if (left > right) {
        return NULL;
    }  else {
        int mid = left + (right - left) / 2;
        t->val = *(nums + mid);
        t->left = sorted_array_to_BST(nums, left, mid - 1);
        t->right = sorted_array_to_BST(nums, mid + 1, right);
    }
    return t;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    TreeNode *root;

    if (!nums || numsSize == 0) {
        return NULL;
    }
    root = sorted_array_to_BST(nums, 0, numsSize - 1);
    return root;
}