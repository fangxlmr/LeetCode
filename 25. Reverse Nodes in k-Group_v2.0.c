/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    typedef struct ListNode Node, *pNode;
    /* 计算链表长度len */
    pNode pCur = head;
    int len = 0;
    while(pCur){
        pCur = pCur->next;
        ++len;
    }

    /* 链表长度不足k个的，直接返回 */
    if(len < k)
        return head;

    /* 大于等于k个的 */
    /* 共有len % k个子链表需反序 */
    pNode dummy = (pNode) malloc(sizeof(Node)); /* 新建一个头结点，也即最后的返回值 */
    dummy->next = NULL;
    pNode pHead = dummy;    /* 头插法的头结点标志，初始为dummy */
    pNode pTail;    /* 记录当前链表的尾结点 */
    pCur = head;    /* 工作指针 */
    while(len >= k){
        int i = 0;
        while(pCur && i < k){     /* 头插法，反序 */
            if(i == 0)
                pTail = pCur;
            pNode p = pCur->next;
            pCur->next = pHead->next;
            pHead->next = pCur;
            pCur = p;
            ++i;
            --len;
        }
        pHead = pTail;   /* 新的头结点 */
    }

    pHead->next = pCur;    /* 拼接链表多余的部分*/

    /* 删除头结点 */
    pNode pDel = dummy;
    dummy = dummy->next;
    free(pDel);
    pDel = NULL;

    return dummy;
}