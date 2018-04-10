/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 用双指针方法，让pFast提前n个结点，而pSlow延迟n个结点，当pFanst = NULL时，pSlow的值即为倒数第n个结点*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    typedef struct ListNode ListNode, *Node;
    Node pSlow = head, pFast = head;   /* 定义双指针，初始值相同，都为head */
    int i = 0;  /* 查找正数第n个结点的标志 */
    while(i < n){   /* 查找正数第n个结点 */
        ++i;
        pFast = pFast->next;
    }

    Node pPre = pSlow;  /* pSlow的前一个结点 */
    while(pFast){
        pFast = pFast->next;
        pPre = pSlow;
        pSlow = pSlow->next;
    }
    if(head->next == NULL){   /* LinkList只有一个结点 */
        free(head);
        head = NULL;
    }
    else if(pSlow == head){  /* 删除的是头节点 */
        head = pSlow->next;
        free(pSlow);
    }
    else{
        pPre->next = pSlow->next;   /*删除的是非头结点 */
        free(pSlow);
    }

    return head;
}