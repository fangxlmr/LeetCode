/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
 * v1.0，笨办法，将二叉树的所有结点递归中序遍历，记录下每个结点的值，同时记录下每个结点的地址
 * 将得到的数组进行排序，之后一次赋值给结点地址
 * */
typedef struct TreeNode TreeNode;
int count = 0;

/* 中序遍历二叉树，将数据存贮到数组中 */
static void bst_inorder (TreeNode *root, int *val, TreeNode **list) {
    if (!root) {
        return;
    }
    bst_inorder(root->left, val, list);
    val[count] = root->val;
    list[count] = root;
    ++count;
    bst_inorder(root->right, val, list);
}

/* 快速排序数组 */
static void quick_sort (int *val, int left, int right) {
    int pivot;  /* 主元元素 */

    if (left > right) {
        return;
    }
    pivot = val[left];
    int i = left, j = right;    /* 左右哨兵 */
    while (i != j) {    /* 两个哨兵相遇条件 */
        /* 查找右侧元素 */
        while (val[j] >= pivot && i < j) {
            --j;
        }
        /* 查找左侧元素 */
        while (val[i] <= pivot && i < j) {
            ++i;
        }
        /* 交换元素 */
        if (i < j) {
            int tmp = val[i];
            val[i] = val[j];
            val[j] = tmp;
        }
    }
    /* 主元元素与中心元素交换，归位 */
    val[left] = val[i];
    val[i] = pivot;
    /* 继续处理左边和右边 */
    quick_sort(val, left, i - 1);
    quick_sort(val, i + 1, right);
}

void recoverTree(struct TreeNode* root) {
    typedef struct TreeNode TreeNode;
    count = 0;

    int val[1000];  /* 结点数据数组 */
    TreeNode *list[1000];   /* 结点指针数组 */
    memset(val,  0, 1000 * sizeof(int));
    memset(list, 0, 1000 * sizeof(TreeNode *));

    /* 中序遍历二叉树，记录数值的同时，记录下对应的节点地址 */
    bst_inorder(root, val, list);
    /* 对结果排序 */
    quick_sort(val, 0, count - 1);

    for (int i = 0; i < count; ++i) {
        list[i]->val = val[i];
    }
}


/* V2.0：Morris 遍历 */
typedef struct TreeNode TreeNode;
void recoverTree(struct TreeNode* root) {
    TreeNode *cur = root, *prev = NULL;     /* Morris遍历使用的变量 */
    TreeNode *first = NULL, *second = NULL; /* 错乱位置标记变量 */

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
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }
            if (!prev->right) {
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = NULL;
                res[count++] = cur->val;
                cur = cur->right;
            }
        }
    }
    *returnSize = count;
    return res;
}