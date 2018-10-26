/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    int i;
    struct ListNode *prev, *cur, *tmp, *p;

    if (m == n) {
        return head;
    } else {
        i = 1;
        cur = head;
        prev = NULL;

        /* Find m-th node. */
        while (i < m && cur) {
            prev = cur;
            cur = cur->next;
            i++;
        }
        p = prev;
        /* reverse linked list while finding n-th node. */
        while (i <= n && cur) {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
            i++;
        }

        /* If m = 1 */
        if (p == NULL) {
            head->next = cur;
            head = prev;
        } else {
            /* If m > 1. */
            p->next->next = cur;
            p->next = prev;
        }
        return head;
    }
}
