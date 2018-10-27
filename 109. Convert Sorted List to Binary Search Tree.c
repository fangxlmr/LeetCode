/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
 * Approach 1: Convert sorted linked list to sorted array,
 * then convert the sorted array to BST.
 * Time complexity: O(N)
 * Space complexity: O(N)
 */
struct TreeNode *convert(int *nums, int left, int right) {
    struct TreeNode *t;

    if (left > right) {
        t = NULL;
    }  else {
        int mid;

        t = (struct TreeNode *) malloc(sizeof(*t));
        if (t != NULL) {
            mid = left + ((right - left) >> 1);   /* left + (right - left) / 2 */
            t->val = *(nums + mid);
            t->left = convert(nums, left, mid - 1);
            t->right = convert(nums, mid + 1, right);
        } else {
            t = NULL;
        }
    }
    return t;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode *root;

    if (numsSize == 0) {
        root = NULL;
    } else {
        root = convert(nums, 0, numsSize - 1);
    }
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int len, i;
    struct ListNode *cur;

    cur = head;
    for (len = 0; cur != NULL; ++len) {
        cur = cur->next;
    }
    if (len == 0) {
        return NULL;
    } else {
        int a[len];
        cur = head;
        for (i = 0; i < len; ++i) {
            a[i] = cur->val;
            cur = cur->next;
        }
        return sortedArrayToBST(a, len);
    }
}

/* Approach 2: Convert linked list to BST directly inspired by binary search.
 * Time complexity: O(N)  todo analyze time complexity.
 * Space complexity: O(logN)
 */
struct TreeNode *convert(struct ListNode *left, struct ListNode *right)
{
    struct ListNode *slow, *fast;
    struct TreeNode *t;

    if (left == right) {
        return NULL;
    } else {
        slow = fast = left;
        /* Find the middle node. */
        while (fast != right && fast->next != right) {
            slow = slow->next;
            fast = fast->next->next;
        }
        /* Create a new TreeNode. */
        t = (struct TreeNode *) malloc(sizeof(*t));
        if (t != NULL) {
            t->val = slow->val;
            t->left = convert(left, slow);
            t->right = convert(slow->next, right);
        }
        return t;
    }
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    struct TreeNode *root;

    if (head == NULL) {
        return NULL;
    } else {
        return convert(head, NULL);
    }
}

/*
 * Approach 3: Convert sorted list to BST directly
 * inspired by inorder traversal of BST.
 * Coped and reproduced from LeetCode answer.
 *
 * Time complexity: O(N)
 * Space complexity: O(logN)
 */
struct ListNode *cur;
struct TreeNode *build_tree(int low,int up)
{
    struct TreeNode *t;
    int mid;

    if(low >= up ) {
        return NULL;
    } else {
        mid = low + ((up - low) >> 1);
        t = malloc(sizeof(*t));

        if (t != NULL) {
            t->left = build_tree(low, mid);
            t->val = cur->val;
            cur = cur->next;
            t->right = build_tree(mid + 1, up);
        }
        return t;
    }
}

struct TreeNode *sortedListToBST(struct ListNode* head) {
    int len = 0;
    cur = head;
    while(head) {
        len++;
        head = head->next;
    }
    return build_tree(0,len);
}
