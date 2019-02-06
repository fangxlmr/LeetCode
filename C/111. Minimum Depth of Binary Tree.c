/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static int min (int x, int y) {
    return (x < y) ? x : y;
}
int minDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    if (!root->left || !root->right) {
        return (root->left) ? minDepth(root->left) + 1 : minDepth(root->right) + 1;
    }
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}