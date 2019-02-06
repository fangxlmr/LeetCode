#include <stdlib.h>
#include <assert.h> /* 待自己实现的assert.h */
#define max(x, y) ((x) > (y) ? (x) : (y))
#define T Stack_T
typedef struct T *T;
typedef struct elem {
    void *x;
    struct elem *next;
}elem;

struct T {
    int count;     /* 栈深度 */
    elem *top;        /* 栈顶 */
};

/* 新建并初始化栈 */
T stack_new (void) {
    T stk;

    stk = (T) malloc(sizeof(struct T));
    stk->count = 0;
    stk->top = NULL;
    return stk;
}


/* 判断栈是否为空，空返回0，不空返回1 */
int stack_empty (T stk) {
    assert(stk);
    return stk->count == 0;
}


/* 栈深度 */
int stack_size (T stk) {
    assert(stk);
    return stk->count;
}


/* 元素入栈 */
void stack_push (T stk, void *x) {
    elem *t;

    assert(stk);
    t = (elem *) malloc(sizeof(elem));
    t->x = x;
    t->next = stk->top;
    stk->top = t;
    stk->count++;
}


/* 元素出栈 */
void *stack_pop (T stk) {
    void *x;
    elem *t;

    assert(stk);
    assert(stk->count > 0);
    t = stk->top;
    stk->top = t->next;
    stk->count--;
    x = t->x;
    free(t);
    return x;
}


/* 释放栈 */
void stack_free (T *stk) {
    elem *t, *u;

    assert(stk && *stk);
    for (t = (*stk)->top; t ; t = u) {
        u = t->next;
        free(t);
    }
    free(*stk);
    *stk = NULL;
}

/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *};
 */
int maxDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}


int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    typedef struct TreeNode TreeNode;
    if (!root) {
        columnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }
    /* 查找二叉树深度 */
    *returnSize = maxDepth(root);

    *columnSizes = (int *) calloc(*returnSize, sizeof(int *));
    /* 待返回的数组 */
    int **res = (int **) malloc(*returnSize * sizeof(int *));


    int level = 0;  /* 记录层数 */
    int size  = 0;  /* 每层的元素个数，也即栈深度 */
    Stack_T stk_left, stk_right;

    stk_left  = stack_new();    /* stk_left 栈与 stk_right 栈*/
    stk_right = stack_new();

    stack_push(stk_right, root);     /* 先将 root 入 stk_right 栈 */
    while (!stack_empty(stk_left) || !stack_empty(stk_right)) {
        TreeNode *p;    /* 二叉树结点循环变量 */
        int i = 0, *one_level;      /* 每层的数组 */

        if (level % 2 == 0) {
            size = stack_size(stk_right);
            one_level = (int *) malloc(size * sizeof(int));
            while (!stack_empty(stk_right)) {
                p = (TreeNode *)stack_pop(stk_right);
                one_level[i++] = p->val;
                if (p->left) {      /* stk_right 栈的元素，先将left元素如 stk_left 栈*/
                    stack_push(stk_left, p->left);
                }
                if (p->right) {
                    stack_push(stk_left, p->right);
                }
            }
        } else {
            size = stack_size(stk_left);
            one_level = (int *) malloc(size * sizeof(int));
            while (!stack_empty(stk_left)) {
                p = (TreeNode *)stack_pop(stk_left);
                one_level[i++] = p->val;
                if (p->right) {      /* stk_right 栈的元素，先将left元素如 stk_left 栈*/
                    stack_push(stk_right, p->right);
                }
                if (p->left) {
                    stack_push(stk_right, p->left);
                }
            }
        }
        (*columnSizes)[level] = size;
        res[level] = one_level;   /* 保存每层的数组地址 */
        level++;
    }
    return res;
}