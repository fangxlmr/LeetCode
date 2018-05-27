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
/* V1.0：递归解法 */
typedef struct TreeNode TreeNode;
int count = 0;  /* 数组位置标记 */
static void inorder (TreeNode *root, int *array) {
    if (!root) {
        return;
    }
    inorder(root->left, array);
    array[count++] = root->val;
    inorder(root->right, array);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    count = 0;
    int *array = (int *) calloc(1000, sizeof(int));
    inorder(root, array);
    *returnSize = count;
    return array;
}


/* V2.0：非递归解法之自定义栈 */
typedef struct TreeNode TreeNode;

typedef struct elem {   /* 栈结点结构 */
    TreeNode *x;
    struct node *next;
}elem;
typedef struct Stack_T {    /* 栈结构 */
    elem *top;
    int size;
}Stack_T;

int count = 0;

static void push (Stack_T *stk, TreeNode *t);
static TreeNode *pop (Stack_T *stk);
static int stack_empty (Stack_T *stk);
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    count = 0;
    Stack_T *stack = (Stack_T *) calloc(1, sizeof(Stack_T));
    int *res = (int *) calloc(1000, sizeof(int));
    TreeNode *p = root;

    while (p || !stack_empty(stack)) {
        if (p) {
            push(stack, p);
            p = p->left;
        } else {
            p = pop(stack);
            res[count++] = p->val;
            p = p->right;
        }
    }
    free(stack);
    *returnSize = count;
    return res;
}


void push (Stack_T *stk, TreeNode *t) {
    elem *p = (elem *) malloc(sizeof(elem));
    p->x = t;
    p->next = stk->top;
    stk->top = p;
    stk->size++;
}

TreeNode *pop (Stack_T *stk) {
    elem *p;
    TreeNode *t;

    p = stk->top;
    stk->top = p->next;
    stk->size--;
    t = p->x;
    free(p);
    return t;
}

int stack_empty (Stack_T *stk) {
    return stk->size == 0;
}

/* V2.0：Morris遍历，线索二叉树
 *
 * Morris中序遍历步骤：
 * 1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
 *
 * 2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
 *
 * a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
 *
 * b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。
 *
 * 3. 重复以上1、2直到当前节点为空。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
typedef struct TreeNode TreeNode;
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    TreeNode *cur = root, *prev = NULL;
    int *res = (int *) malloc(1000 * sizeof(int));
    int count = 0;
    while (cur) {
        if (!cur->left) {
            /*
             * cur左结点为空，输出当前值，并cur = cur->right
             */
            res[count++] = cur->val;
            cur = cur->right;
        } else {
            /*
             * cur左孩子不空，则找到左子树中的前驱结点prev
             * 若前驱结点的右孩子为空，则将前驱结点的右孩子置位当前结点
             * 若前驱结点的右孩子为当前结点，则将前驱结点的右孩子置空
             */
            prev = cur->left;
            /* 找到前驱结点 */
            while (prev->right && prev->right != cur) {  /* 步骤2 */
                prev = prev->right;
            }
            if (!prev->right) {     /* 步骤2a */
                prev->right = cur;
                cur = cur->left;
            } else {            /* 步骤2b */
                prev->right = NULL;
                res[count++] = cur->val;
                cur = cur->right;
            }
        }
    }
    *returnSize = count;
    return res;
}