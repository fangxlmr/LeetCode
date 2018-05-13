/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode, *pTreeNode;

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q)
        return true;
    else if (!(p != NULL && q ))
        return false;
    else if (p && q && p->val != q->val)
        return false;
    else if (!isSameTree(p->left, q->left))
        return false;
    else
        return isSameTree(p->right, q->right);
}