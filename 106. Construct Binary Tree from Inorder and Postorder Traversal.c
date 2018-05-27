/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    typedef struct TreeNode TreeNode;

    if (inorderSize == 0) {
        return NULL;
    }

    int *tmp;
    for (tmp = inorder; tmp < inorder + inorderSize; ++tmp) {
        if (*tmp == *(postorder + postorderSize - 1)) {
            break;
        }
    }
    TreeNode *t = (TreeNode *) malloc(sizeof(struct TreeNode));
    int left_size  = (int) (tmp - inorder);
    int right_size = inorderSize - left_size - 1;
    t->val   = *tmp;
    t->left  = buildTree(inorder, left_size, postorder, left_size);
    t->right = buildTree(tmp + 1, right_size, postorder + left_size, right_size);
    return t;
}