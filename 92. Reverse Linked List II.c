/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode, *pListNode;
void split (pListNode *head, pListNode *new, int m);
void reverse (pListNode *head);
void catenate (pListNode *list1, pListNode *list2);
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    pListNode first  = head, second = NULL, third = NULL;
    split(&first, &second, m);
    split(&second, &third, n - m + 2);
    reverse(&second);
    catenate(&first, &second);
    catenate(&first, &third);
    return first;
}


/* Split a linked list in m-th node,
 * and return the new one (include m-th node).
 * If !head or m <= 1 or m >= length of linked list, no need to split,
 * so return NULL.
 * */
void split (pListNode *head, pListNode *new, int m) {
    if (!*head) {
        *new = NULL;
        return;
    }
    if (m <= 1) {
        *new  = *head;
        *head = NULL;
        return;
    }
    int i = 1;
    pListNode walk = *head;
    while (walk && i < m - 1) {
        ++i;
        walk = walk->next;
    }
    if (walk && i == m - 1) {   /* find m-th node */
        *new = walk->next;
        walk->next = NULL;
    }
}


/* Reverse a linked list */
void reverse (pListNode *head) {
    pListNode dummy = NULL, walk = *head, p; /* p: tmp node */
    while (walk) {
        p = walk;
        walk = walk->next;
        p->next = dummy;
        dummy = p;
    }
    *head = dummy;
}


/* Catenate 2 linked list */
void catenate (pListNode *list1, pListNode *list2) {
    pListNode walk = *list1;
    if (!*list1 || !*list2) {
        *list1 = *list1 ? *list1 : *list2;
        *list2 = NULL;
        return;
    }
    while (walk && walk->next) {
        walk = walk->next;
    }
    if (walk)
        walk->next = *list2;
}