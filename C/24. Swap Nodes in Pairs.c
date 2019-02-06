/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy, *prev, *first, *second;

    dummy.next = head;
    prev = &dummy;
    first = head;

    while (first && (second = first->next)) {
        first->next = second->next;
        prev->next = second;
        second->next = first;

        prev = first;
        first = first->next;
    }

    return dummy.next;
}
