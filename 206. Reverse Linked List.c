/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* #1. Do it iteratively. */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev, *cur, *tmp;

    prev = NULL;
    cur = head;
    while (cur != NULL) {
        tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }

    return prev;
}

/* #2. Do it recursively. */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p;

    if (head == NULL || head->next == NULL) {
        return head;
    } else {
        p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
}
