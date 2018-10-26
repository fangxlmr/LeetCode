/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *prev, *a, *b, *tmp;
    struct ListNode self;

    self.next = head;
    prev = &self;
    while (prev->next && prev->next->next) {
        a = prev->next;
        b = a->next;

        tmp = b->next;
        prev->next = b;
        b->next = a;
        a->next = tmp;

        prev = a;
    }
    return self.next;
}
