/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode *, struct ListNode *);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    typedef struct ListNode ListNode, *Node;

    /*空表，返回null */
    if(listsSize == 0){
        return NULL;
    }
    /* 只有一个链表，直接返回该链表 */
    if(listsSize == 1)
        return lists[0];
    /* 至少2个链表时，合并*/
    int i;
    Node dummy = lists[0];   /* 最终的链表 */
    for(i = 1; i < listsSize; ++i){
        dummy = mergeTwoLists(dummy, lists[i]);
    }

    return dummy;
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    typedef struct ListNode ListNode, *Node;
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    else if( l1 == NULL && l2 == NULL)
        return NULL;

    Node dummy, pTail;  /* dummy 为最终的链表， pTail为工作尾指针 */
    dummy = pTail = (Node) malloc(sizeof(ListNode));    /* 新建头结点 */
    pTail->next = NULL;

    while(l1 && l2){    /* 找到l1，l2中的较大值，插入在pTail后，l1或l2后移*/
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

    pTail->next = l1 ? l1 : l2; /* 处理l1或l2中多余的部分，直接拼接在pTial之后 */

    Node pDel = dummy;  /* 释放头结点 */
    dummy = dummy->next;
    free(pDel);

    return dummy;
}

*/