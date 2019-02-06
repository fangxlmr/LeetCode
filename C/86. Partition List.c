/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode smaller, greater;
    struct ListNode *cur, *scur, *gcur;
    
    cur = head;
    smaller.next = NULL;
    greater.next = NULL;
    scur = &smaller;
    gcur = &greater;

    while (cur != NULL) {
        if (cur->val < x) {
            scur->next = cur;
            scur = cur;
        } else {
            gcur->next = cur;
            gcur = cur;
        }
        cur = cur->next;
    }

    scur->next = greater.next;
    gcur->next = NULL;
    return smaller.next;
}