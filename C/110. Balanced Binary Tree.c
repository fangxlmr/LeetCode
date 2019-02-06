/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static int max (int x, int y) {
    return x > y ? x : y;
}
static int depth (struct TreeNode *root) {
    if (!root) {
        return 0;
    }
    return max(depth(root->left), depth(root->right)) + 1;
}
bool isBalanced(struct TreeNode* root) {
    if (!root) {
        return true;
    }
    return abs(depth(root->left) - depth(root->right)) <= 1 &&
            isBalanced(root->left) && isBalanced(root->right);
}