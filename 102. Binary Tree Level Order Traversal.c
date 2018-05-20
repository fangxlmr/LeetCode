#ifndef BULLET_QUEUE_H
#define BULLET_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>


typedef struct TreeNode TreeNode, *pTreeNode;

/**
 * @brief 用户自定义队列元素类型
 */
typedef pTreeNode QueueElemType;

/**
 * @brief 队列结点结构
 *
 * 用户可以根据自己的需要，增加新的数据
 */
typedef struct QueueNode {
    QueueElemType e;
    struct QueueNode *next;
}QueueNode, *pQueueNode;


/**
 * @brief 队列信息，包括头尾结点
 *
 * 这实际上是对外的接口，引用队列时，都使用 pQueue
 * 用户可以根据自己的需要，增加新的数据
 */
typedef struct Queue {
    pQueueNode front, rear;
}Queue, *pQueue;

/**
 * @brief 生成队列并初始化
 */
extern pQueue queue_create (void);

/**
 * @brief 入队操作
 * @param queue 队列指针
 * @param e     入队元素
 *
 * 入队，是将元素链接到尾结点后
 */
extern void queue_push (pQueue queue, QueueElemType e);

/**
 * @brief 出队操作
 * @param queue 队列指针
 * @return 空队列，返回null。队列不空，返回队头元素
 */
extern void queue_pop (pQueue queue);

/**
 * @brief 销毁队列
 * @param queue 队列指针
 */
extern void queue_destroy (pQueue queue);

/**
 * @brief 清空队列
 * @param queue 指针队列
 */
extern void queue_clear (pQueue queue);

/**
 * @brief 判断队列是否为空
 * @return 空队列返回0.
 */
extern bool queue_empty (pQueue queue);

/**
 * @brief 求队列的长度
 * @param queue
 * @return 空队列返回0。
 */
extern size_t queue_size (pQueue queue);

/**
 * @brief 获取队列头
 */
extern QueueElemType queue_front (pQueue queue);

#endif /* BULLET_QUEUE_H */


/**
 * @brief 判断队列是否为 null
 * @param queue 待检测队列
 */
static void isnull (pQueue queue) {
    if (!queue) {
        printf("Queue of null is used.\n"
               "Program exits with code -1.");
        exit(-1);
    }
}


/**
 * @brief 新建队列，并初始化
 * @return 成功则返回队列指针，失败则返回nll
 *
 * 队列头尾指针保存在结构体 queue中
 */
pQueue queue_create (void) {
    pQueue queue = (pQueue) malloc(sizeof(Queue));
    if (!queue) {
        return NULL;
    }
    queue->front = queue->rear = NULL;
    return queue;
}


/**
 * @brief 入队操作
 * @param queue 队列指针
 * @param e     入队元素
 *
 * 入队，是将元素链接到尾结点后
 */
void queue_push (pQueue queue, QueueElemType e) {
    isnull(queue);
    pQueueNode q = (pQueueNode) malloc(sizeof(QueueNode));
    if (!q){
        return;
    }
    q->e = e;
    q->next = NULL;
    if (!queue->front) {    /* 空队列 */
        queue->front = queue->rear = q;
    } else {         /* 队列非空 */
        queue->rear->next = q;
        queue->rear = q;
    }
}


/**
 * @brief 出队操作
 * @param queue 队列指针
 */
void queue_pop (pQueue queue) {
    isnull(queue);
    pQueueNode node;
    if (queue->front == queue->rear) {
        /* 队列只有一个元素 */
        node = queue->rear;
        queue->rear = queue->front = NULL;
    } else {
        /* 队列有2个及以上的元素 */
        node  = queue->front;
        queue->front = node->next;
    }
    free(node);
}


/**
 * @brief 清空队列
 * @param queue 指针队列
 */
void queue_clear (pQueue queue) {
    isnull(queue);

    /* 队列已经为空队列 */
    if (!queue->front) {
        return;
    }

    /* 队列不空，则清空队列 */
    pQueueNode q;
    while (!queue->front) {
        q = queue->front;
        queue->front = q->next;
        free(q);
    }
    queue->rear = queue->front = NULL;
}


/**
 * @brief 销毁队列
 */
void queue_destroy (pQueue queue) {
    isnull(queue);
    queue_clear(queue);
    free(queue);
    queue = NULL;
}

/**
 * @brief 判断队列是否为空
 */
bool queue_empty (pQueue queue) {
    isnull(queue);
    return (!queue->front) ? true : false;
}

/**
 * @brief 获取队列头
 */
QueueElemType queue_front (pQueue queue) {
    isnull(queue);
    if (!queue_empty(queue)) {
        return queue->front->e;
    } else {
        printf("Warning: Queue is empty. NULL was returned.\n");
        return NULL;
    }
}


/**
 * @brief 查找队列长度
 */
size_t queue_size (pQueue queue) {
    isnull(queue);
    size_t size = 0;
    if (!queue_empty(queue)) {
        pQueueNode walk = queue->front;
        while (walk) {
            ++size;
            walk = walk->next;
        }
    }
    return size;
}


int max (int x, int y) {
    return (x > y) ? x : y;
}

int maxDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *};
 */
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (!root) {
        columnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }
    /* 查找二叉树深度 */
    *returnSize = maxDepth(root);

    int *column_size = (int *) calloc(*returnSize, sizeof(int *));
    *columnSizes = column_size;

    /* 待返回的数组 */
    int **res = (int **) malloc(*returnSize * sizeof(int *));

    /* 层序遍历 */
    pQueue queue = queue_create();

    pTreeNode tmp = NULL;   /* 队列元素的循环变量 */
    int level = 0;  /* 记录层数 */

    /* 先将 root 入队 */
    queue_push(queue, root);

    while (!queue_empty(queue)) {
        /* 每层的结点数，等于当前队列的长度 */
        size_t size = queue_size(queue);

        /* 每层的数组 */
        int *one_level = (int *) malloc(size * sizeof(int));

        /* 遍历队列，存储元素 */
        for (int j = 0; j < size; ++j) {
            tmp = queue_front(queue);

            /* 取出数字元素 */
            one_level[j] = tmp->val;

            /* 孩子结点入队 */
            if (tmp->left) {
                queue_push(queue, tmp->left);
            }
            if (tmp->right) {
                queue_push(queue, tmp->right);
            }
            queue_pop(queue);
        }

        /* 每层的数组存储到 res 中，继续下一层遍历 */
        res[level] = one_level;
        column_size[level] = size;
        ++level;
    }
    return res;
}