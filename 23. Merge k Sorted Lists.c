/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* Approach 1: Compare one by one. */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int i, j;
    struct ListNode head, *rear, *min;

    /* No lists exists. */
    if (listsSize == 0) {
        return NULL;

        /* Only one list. */
    } else if (listsSize == 1) {
        return lists[0];

        /* Two or more lists. */
    } else {
        struct ListNode *index[listsSize];

        head.next = NULL;
        rear = &head;
        /* Index array for show position of each list. */
        for (i = 0; i < listsSize; ++i) {
            index[i] = lists[i];
        }
        while (1) {
            /* Find a non-null list in those lists. */
            j = listsSize;
            for (i = 0; i < listsSize; ++i) {
                if (index[i] != NULL) {
                    min = index[i];
                    j = i;
                    break;
                }
            }
            /* If there still some nodes to be handled. */
            if (j < listsSize) {
                /* Find the min node by comparing one by one. */
                for (i = j + 1; i < listsSize; ++i) {
                    if (index[i] != NULL && min->val > index[i]->val) {
                        min = index[i];
                        j = i;
                    }
                }
                rear->next = min;
                rear = rear->next;
                index[j] = min->next;

                /*
                 * No nodes to be handled which means that all node are
                 * appended to the new list.
                 */
            } else {
                break;
            }
        }
        return head.next;
    }
}

/* Approach 2: Optimize Approach 2 by Priority Queue. */

/* Approach 3: Merge lists one by one. */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy, *rear;

    if (l1 == NULL || l2 == NULL) {
        return l1 ? l1 : l2;
    } else {
        rear = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                rear->next = l1;
                l1 = l1->next;
            } else {
                rear->next = l2;
                l2 = l2->next;
            }
            rear = rear->next;
        }
        rear->next = l1 ? l1 : l2;
        return dummy.next;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int i;
    struct ListNode *head;

    if (listsSize == 0) {
        return NULL;
    } else if (listsSize == 1) {
        return lists[0];
    } else {
        head = lists[0];
        for (i = 1; i < listsSize; ++i) {
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
}

/* Approach 4: Merge with Divide And Conquer */