/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* Version 1.0 */
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


/* Version 2.0*/
typedef struct TreeNode TreeNode;
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0) {
        return NULL;
    }

    int *tmp;
    for (tmp = inorder; tmp < inorder + inorderSize; ++tmp) {
        if (*tmp == *preorder) {
            break;
        }
    }

    TreeNode *t = (TreeNode *) malloc(sizeof(struct TreeNode));
    int left_width  = (int) (tmp - inorder);
    int right_width = inorderSize - left_width - 1;
    t->val   = *tmp;
    t->left  = buildTree(preorder + 1, left_width, inorder, left_width);
    t->right = buildTree(preorder + left_width + 1, right_width, tmp + 1, right_width);
    return t;
}