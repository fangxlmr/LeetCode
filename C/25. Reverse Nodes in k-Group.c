/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int i;
    struct ListNode dummy;
    struct ListNode *left, *right, *next;
    struct ListNode *prev, *cur, *tmp;

    dummy.next = head;
    left = right = head;
    prev = &dummy;

    while (right != NULL) {
        /* Find K nodes. */
        for (i = 1; i < k && right != NULL; ++i) {
            right = right->next;
        }

        /* Left-out nodes. */
        if (right == NULL) {
            break;
            /* Reverse nodes in the list. */
        } else {
            next = right->next;
            cur = left;
            while (cur != next) {
                tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }
            left->next->next = right;
            left->next = next;
        }
        /* Continue walking. */
        prev = left;
        left = right = next;
    }
    return dummy.next;
}
