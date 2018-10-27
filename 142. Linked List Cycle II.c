/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow, *fast;
    int flag;

    flag = 0;
    slow = fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        return NULL;
    } else {
        slow = head;
        /* Find the node which begins the cycle. */
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
}