/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode, *pListNode;
struct ListNode* deleteDuplicates(struct ListNode* head) {
    pListNode *indirect = &head;    /* indirect pointer point to head node */
    while (*indirect && (*indirect)->next) {
        if ((*indirect)->val != (*indirect)->next->val) {
            /* if node, node->next dup, remove node */
            *indirect = (*indirect)->next;
            continue;
        }
        indirect = &(*indirect)->next;  /* Move to next */
    }
    return head;
}