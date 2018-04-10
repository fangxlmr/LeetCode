/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    typedef struct ListNode ListNode, *pNode;
    if(!head || !head->next){
        return head;
    }

    pNode pLeft = head, pRight = head->next;    /* 待交换的双指针 */

    pNode dummy = (pNode) malloc(sizeof(ListNode)); /* 新链表，头结点 */
    pNode pTail = dummy;    /* 新链表，工作尾指针*/

    while(pRight){      /* 偶数个结点 */
        pNode p, q;
        if(pRight->next != NULL){   /* 不是末位结点，保存现场 */
            p = pLeft->next->next, q = pRight->next->next;    /* 保存下一对带交换的结点 */
        }
        else{   /* 链表的末位结点 */
            p = q = NULL;
        }

        pTail->next = pRight;   /* 交换插入新链表 */
        pTail->next->next = pLeft;
        pTail = pLeft;

        pLeft = p;  /* 恢复现场 */
        pRight = q;
    }
    if(pLeft != NULL){ /* 处理奇数个结点多余出来的一个结点 */
        pTail->next = pLeft;
        pTail = pLeft;
    }
    pTail->next = NULL;     /* 链表结束 */

    pNode pDel; /* 删除头结点 */
    pDel= dummy;
    dummy = dummy->next;
    free(pDel);

    return dummy;
}