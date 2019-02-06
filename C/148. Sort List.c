/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge2Lists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy, *tail;

    tail = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    struct ListNode *fast, *slow, *pre;
    
    if (!head || !head->next) {
        return head;
    }
    
    pre = fast = slow = head;
    while (fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = NULL;
    return merge2Lists(sortList(head), sortList(slow));
}