/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 用双指针方法，让 fast 提前n个结点，而 slow 延迟n个结点，当 fast->next = NULL时，slow 的值即为倒数第n个结点*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    typedef struct ListNode ListNode, *pListNode;
    pListNode *slow = &head, *fast = &head;  /* 定义双指针，初始值相同，都为 head */
    int i = 1;
    while(i < n){   /* fast 先行 n 个结点 */
        ++i;
        fast = &(*fast)->next;
    }
    while((*fast)->next){
        fast = &(*fast)->next;
        slow = &(*slow)->next;
    }
    *slow = (*slow)->next;
    return head;
}