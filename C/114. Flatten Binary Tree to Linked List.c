/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* 递归解法 */
void flatten(struct TreeNode* root) {
    if (!root) {
        return;
    }
    if (root->left) {
        flatten(root->left);
    }
    if (root->right) {
        flatten(root->right);
    }
    struct TreeNode *tmp = root->right;
    root->right = root->left;
    root->left  = NULL;
    while (root->right) {
        root = root->right;
    }
    root->right = tmp;
}



/* 非递归解法 */
void flatten(struct TreeNode* root) {
    if (!root) {
        return;
    }
    struct TreeNode *prev = NULL;
    while (root) {
        if (prev = root->left) {
            while (prev->right) {
                prev = prev->right;
            }
            prev->right = root->right;
            root->right = root->left;
            root->left  = NULL;
        }

        root = root->right;
    }
}