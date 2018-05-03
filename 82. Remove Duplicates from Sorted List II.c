/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode, *pListNode;

/* return number n of duplicates begin with current node;
 * if no dup, return 1
*/
int ndup (pListNode);

/* delete n node in a row in the linked list
 * return the pointer pointed to the next node
 */
pListNode deldup (pListNode, int);


struct ListNode* deleteDuplicates(struct ListNode* head) {
    int n;
    /* delete the dups at the beginning */
    while ((n = ndup (head)) > 1) {
        head = deldup (head, n);
    }

    /* delte the dups in the linked list */
    pListNode pCur = head, pPre = head;
    while (pCur) {
        if ((n = ndup (pCur)) > 1) {    /* if there is dups starts from pCur */
            pCur = deldup (pCur, n);
            pPre->next = pCur;
        }
        else {      /* if there is no dups begin with pCur */
            pPre = pCur;
            pCur = pCur->next;
        }
    }

    return head;
}


/* return number n of duplicates begin with current node;
 * if no dup, return 1
*/
int ndup (pListNode lnode) {
    if (!lnode) {
        return 1;
    }
    int n = 1;
    while (lnode && lnode->next && lnode->val == lnode->next->val) {
        ++n;
        lnode = lnode->next;
    }
    return n;
}


/* delete n node in a row in the linked list
 * return the pointer pointed to the next node
 */
pListNode deldup (pListNode node, int n) {
    int i;
    pListNode pCur = node, pDel;
    for (i = 0; i < n; ++i) {
        pDel = pCur;
        pCur = pCur->next;
        free (pDel);
    }
    pDel = NULL;
    return pCur;
}