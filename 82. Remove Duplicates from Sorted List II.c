/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode **walk = &head;
    int dup, flag;

    flag = 0;
    while (*walk) {
        if ((*walk)->next != NULL) {
            dup = (*walk)->val == (*walk)->next->val;
        } else {
            dup = 0;
        }

        if (dup == 1) {
            *walk = (*walk)->next;  /* Delete duplication.  */
            flag = 1;
        } else if (flag == 1) {
            *walk = (*walk)->next;
            flag = 0;
        } else {
            walk = &(*walk)->next;  /* Step forward. */
        }
    }

    return head;
}