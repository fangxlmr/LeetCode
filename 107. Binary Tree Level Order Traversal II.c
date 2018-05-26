#ifndef BULLET_QUEUE_H
#define BULLET_QUEUE_H

#define T Queue_T
typedef struct T *T;

/* 新建队列，并初始化 */
extern T queue_new (void);

/* 判断队列是否为空 */
extern int queue_empty (T que);

/* 队列长度 */
extern int queue_size (T que);

/* 元素入队 */
extern void enqueue (T que, void *x);

/* 元素出队 */
extern void *dequeue (T que);

/* 释放队列，并置NULL */
extern void queue_free (T *que);

#undef T
#endif /* BULLET_QUEUE_H */


#include <stdlib.h>
#include <assert.h>
#define T Queue_T
typedef struct T *T;

typedef struct elem {
    void *x;
    struct elem *next;
}elem;

struct T {
    int count;
    elem *front, *rear;
};


/* 新建队列，并初始化 */
T queue_new (void) {
    T que;

    que = (T) malloc(sizeof(struct T));
    que->count = 0;
    que->front = que->rear = NULL;
    return que;
}


/* 判断队列是否为空 */
int queue_empty (T que) {
    return que->count == 0;
}


/* 队列长度 */
int queue_size (T que) {
    assert(que);
    return que->count;
}


/* 元素入队 */
void enqueue (T que, void *x) {
    elem *t;

    t = (elem *)malloc(sizeof(elem));
    t->x = x;
    t->next = NULL;

    if (queue_empty(que)) {
        que->rear = t;
        que->front = que->rear;
    } else {
        que->rear->next = t;
        que->rear = t;
    }
    que->count++;
}


/* 元素出队 */
void *dequeue (T que) {
    void *x;
    elem *t;

    assert(que);
    assert(que->count > 0);
    if (que->count == 1) {
        /* 队列只有一个元素 */
        t = que->front;
        que->rear = que->front = NULL;
    } else {
        /* 队列有2个及以上的元素 */
        t  = que->front;
        que->front = t->next;
    }
    que->count--;
    x = t->x;
    free(t);
    return x;
}


/* 释放队列 */
void queue_free (T *que) {
    elem *t, *u;

    assert(que && *que);
    for (t = (*que)->front; t; t = u) {
        u = t->next;
        free(t);
    }
    free(*que);
    *que = NULL;
}


int max (int x, int y) {
    return (x > y) ? x : y;
}


int tree_depth (struct TreeNode *root) {
    if (!root) {
        return 0;
    }
    return max(tree_depth(root->left), tree_depth(root->right)) + 1;
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    typedef struct TreeNode TreeNode;
    int level = 0, depth = 0;
    int **res;

    depth = tree_depth(root);
    if (depth == 0) {
        *returnSize = 0;
        *columnSizes = NULL;
        return NULL;
    }
    *returnSize  = depth;
    res = (int **) calloc(depth, sizeof(int *));
    *columnSizes = (int *) malloc(depth * sizeof(int));

    Queue_T queue = queue_new();
    int size;
    TreeNode *p;

    enqueue(queue, root);
    while (!queue_empty(queue)) {
        size = queue_size(queue);
        int *one_level = (int *) malloc(size * sizeof(int));

        for (int i = 0; i < size; ++i) {
            p = (TreeNode *)dequeue(queue);
            one_level[i] = p->val;
            if (p->left) {
                enqueue(queue, p->left);
            }
            if (p->right) {
                enqueue(queue, p->right);
            }
        }

        res[depth - level - 1] = one_level;
        (*columnSizes)[depth - level - 1] = size;
        level++;
    }
    return res;
}