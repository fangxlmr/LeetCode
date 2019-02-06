/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int len, i;
    struct ListNode *cur;
    struct ListNode *slow, *fast;

    /* Find actual operation steps. */
    cur = head;
    for (len = 0; cur != NULL; ++len) {
        cur = cur->next;
    }
    if (len == 0) {
        return NULL;
    } else {
        k %= len;
        /* Rotate list according to k. */
        slow = fast = head;
        for (i = 0; i < k; ++i) {
            fast = fast->next;
        }
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
}