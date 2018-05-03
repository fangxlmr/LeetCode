/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode, *pListNode;
pListNode Rrotate (pListNode);      /* right rotate 1 position of the linked list */
int listlen (pListNode);    /* find the length of linked list */

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head)
        return NULL;
    int len = listlen (head), i;
    if (k > len) {
        k %= len;
    }

    for (i = 0; i < k; ++i) {
        head = Rrotate (head);
    }

    return head;
}


/* right rotate 1 position of the linked list */
pListNode Rrotate (pListNode list) {
    pListNode head = list, rear = list;
    pListNode pre = rear;
    while (rear->next) {    /* find rear and pre node of rear in linked list */
        pre = rear;
        rear = rear->next;
    }
    rear->next = head;  /* rear becomes new head */
    pre->next = NULL;
    return rear;
}


/* find the length of linked list */
int listlen (pListNode list) {
    int n = 0;
    pListNode pCur = list;
    while (pCur) {
        ++n;
        pCur = pCur->next;
    }
    return n;
}