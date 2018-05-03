/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode, *pListNode;


/* is the two adjacent node duplicated? */
bool isdup (pListNode); 


struct ListNode* deleteDuplicates(struct ListNode* head) {
    pListNode pCur = head, pDel = head;
    while (pCur) {
        if (isdup(pCur)) {  /* if duplicate */
            pDel = pCur->next;
            pCur->next = pDel->next;
            free (pDel);
            pDel = NULL;
        }
        else{   /* if no */
            pCur = pCur->next;
        }
    }
    return head;
}


bool isdup (pListNode lnode) {
    if (lnode && lnode->next && lnode->val == lnode->next->val)
        return true;
    else
        return false;
}