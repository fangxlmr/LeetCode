/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    if (!root || (!root->left && !root->right)) {
        return;
    }

    struct TreeLinkNode *t = NULL, *n = NULL;
    if (root->left) {
        root->left->next = root->right;
    }

    t = root->left ? root->left : root->right;
    n = root->next;
    while (n) {
        if (n->left || n->right) {
            break;
        }
        n = n->next;
    }
    if (n && t) {
        t->next = n->left ? n->left : n->right;
    }
    connect(root->left);
    connect(root->right);
}