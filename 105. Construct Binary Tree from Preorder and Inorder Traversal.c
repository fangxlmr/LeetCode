/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;

TreeNode *build_tree (int *preorder, int pleft, int pright, \
                      int *inorder,  int ileft, int iright);

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (!preorder) {
        return NULL;
    }

    TreeNode *root;
    root = build_tree (preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
    return root;
}


TreeNode *build_tree (int *preorder, int pleft, int pright, \
                      int *inorder,  int ileft, int iright) {
    TreeNode *t;

    if (ileft > iright) {
        return NULL;
    }
    /* 根据前序遍历的第一个值，查找中序遍历的根结点位置 */
    int i;
    for (i = ileft; i <= iright; ++i) {
        if (inorder[i] == preorder[pleft]) {
            break;
        }
    }

    t = (TreeNode *) malloc(sizeof(struct TreeNode));
    t->val   = preorder[pleft];
    t->left  = build_tree(preorder, pleft + 1, pleft + i - ileft, inorder, ileft, i - 1);
    t->right = build_tree(preorder, pleft + i - ileft + 1, pright, inorder, i + 1, iright);
    return t;
}