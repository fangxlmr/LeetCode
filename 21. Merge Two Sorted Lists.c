/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    typedef struct ListNode ListNode, *pListNode;
    if (!l1 || !l2)    /* l1 或 l2 为 null */
        return l1 ? l1 : l2;

    pListNode dummy, rear;
    dummy = rear = (pListNode) malloc(sizeof(ListNode));
    rear->next = NULL;

    while (l1 && l2){   /* 处理公共部分，选出较大值接在rear后 */
        if (l1->val < l2->val){
            rear->next = l1;
            l1 = l1->next;
        } else {
            rear->next = l2;
            l2 = l2->next;
        }
        rear = rear->next;
    }
    rear->next = l1 ? l1 : l2;  /* 处理多余部分 */
    pListNode p = dummy;    /* free redundant head node */
    dummy = dummy->next;
    free(p);
    return dummy;
}