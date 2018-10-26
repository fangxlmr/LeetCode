/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head, *prev;
    int sum, carry;

    head = l1;
    carry = 0;
    while (l1 && l2) {
        sum = l1->val + l2->val + carry;
        l1->val = sum % 10;
        carry = sum / 10;
        prev = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    l1 = l1 ? l1 : l2;
    prev->next = l1;
    while (l1) {
        prev = l1;
        sum = l1->val + carry;
        l1->val = sum % 10;
        carry = sum / 10;
        l1 = l1->next;
    }
    if (carry == 1) {
        struct ListNode *p;
        p = malloc(sizeof(struct ListNode));
        p->val = carry;
        p->next = NULL;

        prev->next = p;
    }
    return head;
}
