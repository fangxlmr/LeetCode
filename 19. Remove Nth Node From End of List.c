/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/* Fast and slow pointers. */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int i;
    struct ListNode **fast, **slow;

    i = 1;
    fast = slow = &head;
    while(i < n){
        fast = &(*fast)->next;
        i++;
    }
    while((*fast)->next){
        fast = &(*fast)->next;
        slow = &(*slow)->next;
    }
    *slow = (*slow)->next;
    return head;
}