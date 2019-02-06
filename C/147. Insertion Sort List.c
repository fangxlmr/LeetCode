/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
 * My code is clean and meet the requirement of insertion
 * sort. However, my runtime is 32ms which beats ~42% people
 * on LeetCode. I saw the code whose runtime is 4ms beats 100%.
 * We have the same concept. The only difference is I implement
 * it in a while loop instead of a separate function.
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode dummy, **walk, *rear;
    struct ListNode *cur;

    dummy.next = NULL;
    rear = &dummy;
    cur = head;
    while (cur) {
        head = cur->next;

        /* Insert to dummy list. */
        walk = &dummy.next;
        while (*walk != NULL && (*walk)->val <= cur->val) {
            walk = &(*walk)->next;
        }
        cur->next = *walk;
        *walk = cur;

        cur = head;
    }
    return dummy.next;
}