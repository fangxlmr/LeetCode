/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode, *pListNode;
pListNode merge_2 (pListNode, pListNode);
pListNode merge_k (pListNode *lists, int left, int right);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) {
        return NULL;
    }
    return merge_k(lists, 0, listsSize-1);
}


/* merge k lists */
pListNode merge_k (pListNode *lists, int left, int right) {
    if (right == left) {
        return lists[left];
    }
    if (right - left == 1) {
        return merge_2(lists[left], lists[right]);
    }
    int mid = left + (right - left) / 2;
    return merge_2(merge_k(lists, left, mid), merge_k(lists, mid + 1, right));
}


/* merge 2 lists */
pListNode merge_2 (struct ListNode* l1, struct ListNode* l2) {
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