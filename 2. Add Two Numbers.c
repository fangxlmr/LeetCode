/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode, *pListNode;


pListNode addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    pListNode walk1 = l1, walk2 = l2, p; /* p: tmp node */
    pListNode head = (pListNode) calloc(1, sizeof(ListNode));
    pListNode rear = head;
    int carray = 0, sum = 0;
    while (walk1 && walk2) {    /* 公共部分相加 */
        p = (pListNode) malloc(sizeof(ListNode));
        sum = walk1->val + walk2->val + carray;
        p->val = sum % 10;
        carray = sum / 10;
        rear->next = p;
        rear = p;

        walk1 = walk1->next;
        walk2 = walk2->next;
    }
    walk1 = walk1 ? walk1 : walk2;
    while (walk1) {     /* 多余的部分相加 */
        p = (pListNode) malloc(sizeof(ListNode));
        sum = walk1->val + carray;
        p->val = sum % 10;
        carray = sum / 10;
        rear->next = p;
        rear = p;

        walk1 = walk1->next;
    }
    if (carray == 1) {  /* 最终进位处理 */
        p = (pListNode) malloc(sizeof(ListNode));
        p->val = carray;
        rear->next = p;
        rear = p;
    }

    rear->next = NULL;
    p = head;   /* free多余的头结点 */
    head = head->next;
    free(p);
    return head;
}