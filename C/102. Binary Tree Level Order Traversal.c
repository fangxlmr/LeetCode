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
#define MAX 1024
static struct TreeNode *queue[MAX];
static int head = 0;
static int tail = 0;

static int enqueue(struct TreeNode *x)
{
    if ((tail + 1) % MAX == head) {
        return -1;
    } else {
        queue[tail] = x;
        tail = (tail + 1) % MAX;
        return 0;
    }
}

static int dequeue(struct TreeNode **x)
{
    if (head == tail) {
        return -1;
    } else {
        *x = queue[head];
        head = (head + 1) % MAX;
        return 0;
    }
}

static int queue_isempty(void)
{
    return head == tail;
}

static size_t queue_get_size(void)
{
    if (tail >= head) {
        return tail - head;
    } else {
        return MAX - (head - tail);
    }
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (!root) {
        columnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }
    struct TreeNode *tmp;
    int i, level = 0;
    int **res, *items;

    *returnSize = MAX;
    *columnSizes = (int *) malloc(*returnSize * sizeof(int));
    res = (int **) malloc(*returnSize * sizeof(int *));

    enqueue(root);
    while (queue_isempty() == 0) {
        size_t size = queue_get_size();
        (*columnSizes)[level] = size;
        items = (int *) malloc(size * sizeof(int));

        for (i = 0; i < size; ++i) {
            dequeue(&tmp);
            items[i] = tmp->val;
            if (tmp->left) {
                enqueue(tmp->left);
            }
            if (tmp->right) {
                enqueue(tmp->right);
            }
        }

        res[level] = items;
        ++level;
    }
    *returnSize = level;
    return res;
}

#undef MAX