/*
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


// recursive solution
typedef struct TreeNode TreeNode, *pTreeNode;
typedef struct LinkedList
{
    int val;
    struct LinkedList *next;
}LinkedList, *pLinkedList;


pLinkedList inoder_traversal (pTreeNode, pLinkedList);
pLinkedList linked_list_append (pTreeNode, pLinkedList);
int linked_list_length (pLinkedList);

int* inorderTraversal (struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root)
        return NULL;

    pLinkedList head = (pLinkedList) malloc (sizeof(LinkedList));
    head->val = 0;
    head->next = NULL;
    inoder_traversal (root, head);  /* have finished inorder traversal */
    *returnSize = linked_list_length (head);    /* find the length of the LinkedList */
    int *return_array = (int *) calloc (*returnSize, sizeof(int));
    pLinkedList pCur = head->next;
    int i;
    for (i = 0; i < *returnSize; ++i) {
        *(return_array + i) = pCur->val;
        pCur = pCur->next;
    }
    return return_array;
}



/* inorder traversal of the binary tree */
pLinkedList inoder_traversal (pTreeNode root, pLinkedList rear) {
    if (root == NULL)
        return;
    rear = inoder_traversal (root->left, rear);    /* inorder traversal */
    rear = linked_list_append (root, rear);
    rear = inoder_traversal (root->right, rear);
}


/* append element at the rear of LinkedList */
pLinkedList linked_list_append (pTreeNode root, pLinkedList rear) {
    if (!root) {
        return rear;
    }
    pLinkedList pNew = (pLinkedList) malloc (sizeof(LinkedList));     /* new node of LinkedList */
    pNew->val = root->val;
    pNew->next = NULL;
    rear->next = pNew;
    rear = pNew;
    return rear;
}


/* find the length of LinkedList */
int linked_list_length (pLinkedList head) {
    int i = 0;
    pLinkedList pCur = head->next;
    while (pCur) {
        ++i;
        pCur = pCur->next;
    }
    return i;
}