/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
 * Approach 1: Testing NULL pointer in a limited time, say 0.5s.
 * Then we think it has a loop after 0.5s when current node still
 * not meet NULL pointer.
 */
/* Approach 2: Hashtable or set. */
/* Approach 3: Two pointers. */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow, *fast;

    slow = fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}