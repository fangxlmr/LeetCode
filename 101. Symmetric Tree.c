/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 /* 这段代码本身没有问题，但是有逻辑bug
  * 判断是否为对称树，我的想法是
  * 中序遍历（或后序遍历），存储每个结点的数值到数组中
  * 判断数组元素的对称性
  * 但是，这种方法不能处理类似这样的非对称二叉树
  * [1,2,3,3,null,2,null]
  * 逻辑上不对
  * 因此，还是得用简单的递归逻辑
  * */

/* V1.0 */
/*
#define MAXSIZE 1000
typedef struct TreeNode TreeNode, *pTreeNode;
typedef struct Array {
    int tree[MAXSIZE];
    int sp;
}Array, *pArray;

void intraversal (pTreeNode root, pArray T);
void save (pTreeNode root, pArray T);

bool isSymmetric(struct TreeNode* root) {
    if (!root) {
        return true;
    }
    pArray tarray = (pArray) malloc(sizeof(Array));
    memset(tarray, 0, sizeof(Array));
    intraversal(root, tarray);
    if (tarray->sp % 2 == 0)
        return false;
    for (int i = 0; i <= tarray->sp / 2; ++i) {
        if (tarray->tree[i] != tarray->tree[tarray->sp - i - 1])
            return false;
    }
    return true;
}


void intraversal (pTreeNode root, pArray T) {
    if (!root){
        return;
    }
    intraversal(root->left, T);
    save(root, T);
    intraversal(root->right, T);
}

void save (pTreeNode root, pArray T) {
    if (T && root)
        T->tree[T->sp++] = root->val;
    return;
}*/


/* V2.0 */
/* recursive solution */
/* 比较root1->left 与 root2->right, 和
 * root2->right与root2->left是否相等
 * 递归运行
 * */
typedef struct TreeNode TreeNode, *pTreeNode;
bool isMirror (pTreeNode root1, pTreeNode root2);
bool isSymmetric(struct TreeNode* root) {
    return isMirror(root, root);
}

bool isMirror (pTreeNode root1, pTreeNode root2) {
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    return root1->val == root2->val &&
           isMirror(root1->left, root2->right) &&
           isMirror(root1->right, root2->left);
}


/* V3.0: iterative solution using queue */
/* use my own lib: queue.h & queue.c */
/* 用队列去实现，每次 pop 两个元素t1, t2 出来比较，相同则依次将
 * t1->left, t2->right, t1->right, t2->left push进队列
 * */
typedef struct TreeNode TreeNode, *pTreeNode;
bool isSymmetric(struct TreeNode* root) {
    if (!root)
        return true;
    pQueue queue = queue_new();
    queue_push(queue, root);
    queue_push(queue, root);
    while (!queue_isempty(queue)) {
        QueueElemType t1 = queue_gethead(queue);
        queue_pop(queue);
        QueueElemType t2 = queue_gethead(queue);
        queue_pop(queue);
        if (t1 == NULL && t2 == NULL)
            continue;
        if (t1 == NULL || t2 == NULL)
            return false;
        if (t1->val != t2->val)
            return false;
        /* a reflection */
        queue_push(queue, t1->left);
        queue_push(queue, t2->right);
        queue_push(queue, t1->right);
        queue_push(queue, t2->left);
    }
    return true;
}