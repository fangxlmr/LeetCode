/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 /*
  * V1.0: O(n) space complexity, inorder traversal
  * Need a linked list to store each node in inorder traversal
  * */
//typedef struct TreeNode TreeNode, *pTreeNode;
//typedef struct Node {
//    int val;
//    struct Node *next;
//}Node, *pNode;
//
//void intraversal (pTreeNode root, pNode head);
//
//bool isValidBST(struct TreeNode* root) {
//    /*root == NULL or only root node */
//    if (!root || (!root->left && !root->right))
//        return true;
//    pNode head = (pNode) calloc(1, sizeof(Node));
//    /* get the reverse order of inorder traversal of BST */
//    intraversal(root, head);
//
//    /* check it qualify a BST or not */
//    pNode pPre = head->next, pCur = pPre->next;
//    while (pCur) {
//        if (pPre->val <= pCur->val)
//            return false;
//        pPre = pCur;
//        pCur = pCur->next;
//    }
//    pNode pDel = head;
//    while (head) {
//        head = head->next;
//        free(pDel);
//        pDel = head;
//    }
//    return true;
//}
//
//
///* inorder traversal of BST */
//void intraversal (pTreeNode root, pNode head) {
//    if (!root)
//        return;
//    intraversal(root->left, head);
//
//    /* store each node in a linked list */
//    pNode p = (pNode) calloc(1, sizeof(Node));
//    p->val  = root->val;
//    p->next = head->next;   /* front inserting */
//    head->next = p;
//
//    intraversal(root->right, head);
//}


/*
 * V2.0: improved inorder traversal, O(1) space complexity
 * Do not need a linked list to store each node of BST
 *
 * */
typedef struct TreeNode TreeNode, *pTreeNode;
pTreeNode pre = NULL;

bool isValidBST(struct TreeNode* root) {
    if (root != NULL){
        if (!isValidBST(root->left))
            return false;
        if (pre != NULL && root->val <= pre->val)
            return false;
        pre = root;
        return isValidBST(root->right);
    }
    return true;
}