/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode, *pListNode;

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    /* if m = n, don't have to reverse */
    if (m == n)
        return head;
    /* if m != n
    /* add a head node to the linked list, 
     * in order to split it into 3 parts in whatever conditions
     */
    pListNode new_head = (pListNode) calloc (1, sizeof(ListNode));
    new_head->next = head;
    head = new_head;

    pListNode pCur = head;
    int i = 0;
    /* find (m - 1)-th node */
    while (i < m - 1) {
        pCur = pCur->next;
        ++i;
    }
    pListNode pre_mNode = pCur; /* (m - 1)-th node */
    pCur = pCur->next;      /* m-th node */
    pListNode pFlag = pCur;  /* m-th node flag */
    /* now, i = m - 1 */
    i = m;
    pListNode p = pCur;     /* tmp node p */
    while (pCur && i <= n) {
        p = pCur;
        pCur = pCur->next;
        p->next = pre_mNode->next;
        pre_mNode->next = p;
        ++i;
    }
    if (pFlag)
        pFlag->next = pCur;

    new_head = head;
    head = new_head->next;
    free (new_head);
    new_head = NULL;
    return head;

}