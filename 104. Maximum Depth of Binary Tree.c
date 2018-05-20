/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * max - return max of x and y
 * @param x
 * @param y
 * @return max of x and y
 */
int max (int x, int y) {
    return (x > y) ? x : y;
}

int maxDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}