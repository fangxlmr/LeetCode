/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode, *pListNode;
struct ListNode* deleteDuplicates(struct ListNode* head) {
    pListNode *indirect = &head;
    int flag = 0, value = 0;     /* to store dup value */
    while (*indirect) {
        if ((*indirect)->next && (*indirect)->val == (*indirect)->next->val) {
            /* if node, node->next dup, remove node */
            *indirect = (*indirect)->next;
            flag = 1;
            continue;
        }
        if (flag) {
            /* if dup, remove node->next in while loop */
            *indirect = (*indirect)->next;
            flag = 0;
        } else {
            indirect = &(*indirect)->next;  /* move to next */
        }
    }
    return head;
}