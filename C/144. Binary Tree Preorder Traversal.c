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
int count = 0;

static void preorder (TreeNode *root, int *array) {
    if (!root) {
        return;
    }
    array[count++] = root->val;
    inorder(root->left, array);
    inorder(root->right, array);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    count = 0;
    int *array = (int *) malloc(1000 * sizeof(int));
    preorder(root, array);
    *returnSize = count;
    return array;
}


/* V2.0：非递归解法之自定义栈 */
typedef struct TreeNode TreeNode;
typedef struct elem {   /* 栈结点结构 */
    TreeNode *x;
    struct elem *next;
}elem;

typedef struct Stack_T {        /* 栈结构 */
    elem *top;  /* 栈顶 */
    int size;  /* 栈深度 */
}Stack_T;

static int stack_empty (Stack_T *stk) {
    assert(stk);
    return stk->size == 0;
}

static void push (Stack_T *stk, TreeNode *t) {
    if (!stk) {
        return;
    }

    elem *e = (elem *) malloc(sizeof(elem));
    e->x = t;
    e->next = stk->top;
    stk->top = e;
    ++stk->size;
}

static TreeNode *pop (Stack_T *stk) {
    assert(stk);
    if (stack_empty(stk)) {
        return NULL;
    }
    TreeNode *t;
    elem *e;

    e = stk->top;
    stk->top = e->next;
    --stk->size;
    t = e->x;
    free(e);
    return t;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    Stack_T *stack;
    TreeNode *t;
    int *res, count = 0;   /* 返回的数组 */

    stack = (Stack_T *) calloc(1, sizeof(Stack_T));
    t = root;
    res = (int *) malloc(1000 * sizeof(int));

    while (t || !stack_empty(stack)) {
        if (t) {
            push(stack, t);
            res[count++] = t->val;
            t = t->left;
        } else {
            t = pop(stack);
            t = t->right;
        }
    }
    *returnSize = count;
    free(stack);
    return res;
}


/* V3.0：非递归解法之Morris遍历，线索二叉树 */
typedef struct TreeNode TreeNode;

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    /* 与中序遍历的写法类似 */
    TreeNode *prev = NULL, *cur = root;
    int *res = (int *) malloc(1000 * sizeof(int));
    int count = 0;

    while (cur) {
        if (!cur->left) {
            res[count++] = cur->val;
            cur = cur->right;
        } else {
            prev = cur->left;

            /* 找到直接前驱 */
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }
            if (!prev->right) { /* 第一次遍历，线索化 */
                res[count++] = cur->val;       /* 与中序遍历唯一不同的地方：输出的位置不同 */
                prev->right = cur;
                cur = cur->left;
            } else {        /* 第二次遍历，访问结点，重置线索化 */
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    *returnSize = count;
    return res;
}