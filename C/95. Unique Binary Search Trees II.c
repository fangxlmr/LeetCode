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

/* my own version, takes 12ms in LeetCode
 * it is a little complicated
 * there is a more clear version as showing at the end of this file
 * */
/*



typedef struct TreeNode TreeNode, *pTreeNode;

typedef struct Node {   */
/* linked list node structure *//*

    pTreeNode t;
    struct Node *next;
}Node, *pNode;


int total_num (int n);
pNode ntrees (int left, int right);
pNode copy (pNode const p);
pTreeNode dup (pTreeNode p);
void linked_list_free (pNode L);
pTreeNode *generateTrees(int n, int* returnSize);


struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0)     */
/* no such BST *//*

        return NULL;
    pNode head = NULL;  */
/* all roots of possible trees was stored in a linked list *//*

    head = ntrees (1, n);
    *returnSize = total_num(n);
    printf("returnSize = %d\n", *returnSize);
    pTreeNode *res = (pTreeNode *) calloc(*returnSize, sizeof(TreeNode));
    pNode pCur = head;
    int i = 0;
    while (pCur) {
        res[i] = pCur->t;
        printf("line %d: t = %d\n", i, res[i]->val);
        pCur = pCur->next;
        ++i;
    }
    return res;
}


pNode ntrees (int left, int right) {
    */
/* head node of linked list res *//*

    pNode res  = (pNode) calloc(1, sizeof(Node));
    pNode pRes = res;
    if (left > right) {   */
/* return a node of NULL of linked list *//*

        res->t = NULL;
        res->next = NULL;
        return res;
    }

    int i;    */
/* backtrack for each number from left to right *//*

    for (i = left; i <= right; ++i) {
        pNode lefts  = ntrees(left, i - 1);     */
/* the total of left  trees of node i *//*

        pNode rights = ntrees(i + 1, right);    */
/* the total of right trees of node i *//*

        pNode pLeft  = lefts;
        pNode pRight = rights;

        while (pLeft) {
            while (pRight) {
                */
/* each possible root of BST *//*

                pTreeNode root = (pTreeNode) calloc(1, sizeof(TreeNode));
                root->val   = i;
                root->left  = copy(pLeft)->t;
                root->right = copy(pRight)->t;

                */
/* save root node in linked list res *//*

                pNode pNew = (pNode) calloc(1, sizeof(Node));
                pNew->t = root;
                pRes->next = pNew;
                pRes = pNew;

                pRight = pRight->next;  */
/* iterate rights *//*

            }
            pLeft  = pLeft->next;    */
/* iterate lefts *//*

            pRight = rights;
        }

        linked_list_free(lefts);     */
/* free linked list: lefts and rights *//*

        linked_list_free(rights);
    }
    pRes->next = NULL;
    pNode del = res;    */
/* free head node *//*

    res = res->next;
    free(del);
    return res;
}


*/
/* total of possible trees *//*

static int total_num (int n) {
    if (n < 0) {
        return 0;
    }
    int num[n + 1];
    memset (num, 0, sizeof(num));
    int i, j;
    num[0] = num[1] = 1;
    for (i = 2; i <= n; ++i) {
        for (j = 0; j < i; ++j){
            num[i] += num[j] * num[i - 1 - j];
        }
    }
    return num[n];
}


*/
/*
 * copy a linked list node
 * which stored the root node of possible BST
 *
 * *//*

pNode copy (const pNode p) {
    if (!p)
        return NULL;
    pNode q = (pNode) calloc(1, sizeof(Node));
    q->t = dup(p->t);
    return q;
}


*/
/* duplicate a BST, return root2 *//*

pTreeNode dup (pTreeNode root) {
    if (!root)
        return NULL;
    pTreeNode root2 = (pTreeNode) calloc(1, sizeof(TreeNode));
    root2->val   = root->val;
    root2->left  = dup(root->left);
    root2->right = dup(root->right);
    return root2;
}


*/
/* free a linked list *//*

void linked_list_free (pNode L) {
    pNode pDel = L;
    while (pDel) {
        L = L->next;
        free(pDel);
        pDel = L;
    }
    return;
}*/


/* improved version from LeetCode */
typedef struct TreeNode TreeNode, *pTreeNode;
static int total_num (int n);
static pTreeNode *ntrees (int start, int end, int *size);

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n < 1 || returnSize == NULL) {
        return NULL;
    }
    return ntrees(1, n, returnSize);
}

static int total_num (int n) {
    if (n <= 0) {
        return 0;
    }
    int num[n + 1];
    memset(num, 0, sizeof(num));
    num[0] = num[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j){
            num[i] += num[j] * num[i - 1 - j];
        }
    }
    return num[n];
}

static pTreeNode *ntrees(int start, int end, int *size) {
    int capacity = total_num(end - start + 1);  /* total of possible results */
    /* new array to store the results */
    pTreeNode *res = (pTreeNode *) calloc(capacity, sizeof(pTreeNode));
    *size = 0;
    if (start > end) {  /* no valid value */
        res[(*size)++] = NULL;
        return res;
    }
    /* backtraking */
    for (int k = start; k <= end; ++k) {
        int left_size  = 0;
        int right_size = 0;
        pTreeNode *lefts  = ntrees(start, k - 1, &left_size);
        pTreeNode *rights = ntrees(k + 1, end,   &right_size);

        /* save all possible BSTs */
        for (int i = 0; i < left_size; ++i) {
            for (int j = 0; j < right_size; ++j) {
                pTreeNode root = (pTreeNode) malloc(sizeof(TreeNode));
                root->val   = k;    /* new BSTs' root */
                root->left  = lefts[i];
                root->right = rights[j];
                /* save root into res, *size move to next free position*/
                res[(*size)++] = root;
            }
        }
        free(lefts);
        free(rights);
    }
    return res;
}