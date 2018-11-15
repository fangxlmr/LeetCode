/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/* Approach 1: Recursive traversal. [Time Limit Exceeded] */
int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

/* Approach 2: Optimized recursive solution. [Accepted] */
int countNodes(struct TreeNode* root) {
    int hleft, hright;
    struct TreeNode *pleft, *pright;

    if (!root) {
        return 0;
    } else {
        hleft = hright = 0;
        pleft = pright = root;

        while (pleft) {
            pleft = pleft->left;
            hleft++;
        }
        while (pright) {
            pright = pright->right;
            hright++;
        }

        if (hleft == hright) {
            return pow(2, hleft) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
}

/* Approach 3: A recursive solution copied from submitted answer. [Accepted]
 *
 * from: https://leetcode.com/submissions/detail/189713790/
 */
int countNodes(struct TreeNode* root) {
    int hleft, hright;
    struct TreeNode *pleft, *pright;

    if (!root) {
        return 0;
    } else {
        hleft = hright = 0;
        pleft = root->left;
        pright = root->right;

        /* This is the most tricky part. */
        while (pleft) {
            pleft = pleft->left;
            hleft++;
        }
        while (pright) {
            pright = pright->left;
            hright++;
        }
        if (hleft == hright) {
            return 1 + (1 << hleft) - 1 + countNodes(root->right);
        } else {
            return 1 + (1 << hright) - 1 +countNodes(root->left);
        }
    }
}

/* Approach 4: Surely, we can use BFS by queue. */