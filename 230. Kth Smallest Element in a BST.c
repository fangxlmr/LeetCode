/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/* Approach 1: Inspired by in-order traversal. If find the k-th
 * smallest number, return immediately without further traversing.
 * [Accepted]
 */
void helper(struct TreeNode *root, int k, int *ctr, int *data)
{
    if (!root) {
        return;
    }

    helper(root->left, k, ctr, data);
    (*ctr)++;
    if (*ctr == k) {
        *data = root->val;
        return;
    } else {
      helper(root->right, k, ctr, data);
    }
}

int kthSmallest(struct TreeNode* root, int k) {
    int ctr, data;
    helper(root, k, &ctr, &data);
    return data;
}

/* Approach 2: Inspired by binary search. */
int count(struct TreeNode *root)
{
    if (!root) {
        return 0;
    } else {
        return 1 + count(root->left) + count(root->right);
    }
}
int kthSmallest(struct TreeNode* root, int k) {
    int cnt;

    if (!root) {
        return 0;
    }
    cnt = count(root->left);
    if (k == cnt + 1) {
        return root->val;
    } else if (k < cnt + 1) {
        return kthSmallest(root->left, k--);
    } else {
        return kthSmallest(root->right, k - cnt - 1);
    }
}
