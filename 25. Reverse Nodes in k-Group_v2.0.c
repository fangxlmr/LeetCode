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
    pNode pBegin = head, pEnd = head; /* k个结点的起止位置标志 */
    while(len >= k){
        pHead = pEnd;   /* 重置头结点 */
        int i = 0;
        while(pEnd && i < k){     /* 找到第k个结点 */
            pEnd = pEnd->next;
            ++i;
        }
        while(pBegin < pEnd){
            insert(pHead, pBegin);  /* 头插法，插入 */
            pBegin = pBegin->next;
        }
        len -= k;   /* 更新长度 */
    }

    pHead->next = pCur;    /* 拼接链表多余的部分*/

    /* 删除头结点 */
    pNode pDel = dummy;
    dummy = dummy->next;
    free(pDel);
    pDel = NULL;

    return dummy;
}