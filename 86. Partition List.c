/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode, *pListNode;


struct ListNode* partition(struct ListNode* head, int x) {
    /* a linked list for storing node less than x */
    pListNode smaller = (pListNode) calloc (1, sizeof(ListNode));

    /* a linked list for storing node greater than x */
    pListNode greater = (pListNode) calloc (1, sizeof(ListNode));

    pListNode sCur = smaller, gCur = greater, pCur = head;
    while (pCur) {
        if (pCur->val < x) {
            /* if node < x, strore it in smaller */
            sCur->next = pCur;
            pCur = pCur->next;
            sCur = sCur->next;
        }
        else {
            /* if node >= x, store it in greater */
            gCur->next = pCur;
            pCur = pCur->next;
            gCur = gCur->next;
        }
    }

    
    sCur->next = greater->next;     /* catenate smaller and greater */
    gCur->next = NULL;
    free (greater);     /* free head node of greater */
    greater = NULL;
    pListNode pDel = smaller;   /* free head ndoe of smaller */
    smaller = smaller->next;
    free (pDel);
    pDel = NULL;
    /* return the new linked list */
    return smaller;
}