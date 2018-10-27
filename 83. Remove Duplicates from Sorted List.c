/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode **walk = &head;

    while (*walk) {
        if ((*walk)->next && (*walk)->val == (*walk)->next->val) {
            *walk = (*walk)->next;
        } else {
            walk = &(*walk)->next;
        }
    }
    return head;
}