/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct TreeNode TreeNode, *pTreeNode;


void inoder_traversal (pTreeNode root, int *array, int *size) {
    if (root == NULL)
        return;
    inoder_traversal (root->left, array, size);
    array[*size] = root->val;
    *size += 1;
    inoder_traversal (root->right, array, size);
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root)
        return NULL;

    int *returnArray = (int *) calloc(1000, sizeof(int));
    if(!returnArray) {
        printf("malloc failed. program exiting...\n");
        exit(-1);
    }
    inoder_traversal (root, returnArray, returnSize);
    return returnArray;
}
