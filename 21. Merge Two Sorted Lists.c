/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    typedef struct ListNode ListNode, *Node;
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    else if( l1 == NULL && l2 == NULL)
        return NULL;

    Node dummy, pTail;
    dummy = pTail = (Node) malloc(sizeof(ListNode));
    pTail->next = NULL;

    while(l1 && l2){
        if(l1->val < l2->val){
            pTail->next = l1;
            l1 = l1->next;
        }
        else{
            pTail->next = l2;
            l2 = l2->next;
        }
        pTail = pTail->next;
    }

    pTail->next = l1 ? l1 : l2;

    return dummy->next;
}