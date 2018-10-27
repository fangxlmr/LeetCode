/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    struct ListNode *slow, *fast, *tmp;

    if (head) {
        /* Find mid. */
        slow = fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        /* Reverse second half of the list. */
        fast = slow->next;
        while (fast) {
            tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }
        fast = slow;

        /* Reorder the list. */
        slow = head;
        while (slow != fast && slow->next != fast) {
            tmp = fast->next;
            fast->next = slow->next;
            slow->next = fast;
            slow = fast->next;
            fast = tmp;
        }
        fast->next = NULL;
    }
}