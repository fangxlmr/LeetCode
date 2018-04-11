/*
 *
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    typedef struct ListNode Node, *pNode;
    pNode pLeft = head, pRight = head;  /* 带交换的两个指针*/
    pNode dummy = (pNode) malloc(sizeof(Node)); /* 新建一个头结点，也即最后的返回值 */
    pNode pIns;     /* 头插法的插入节点 */

    int i = 0;
    while(i <= k && !pRight){   /* 查找到第k个结点 */
        pRight = pRight->next;
        ++i;
    }
    if(pRight){     /* 一般情况，查找到k个结点 */
        pNode p = pLeft->next;  /* 头插法，倒序插入 */
        pLeft->next = pIns->next;
        pIns->next = pLeft;
        pLeft = p;
    }

}