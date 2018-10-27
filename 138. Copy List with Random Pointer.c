/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
/*
 * Approach 1: Iterative solution with O(N) space by dict (hashmap).
 * I never test it, but I think it could work.
 */
struct RandomListNode *get_list_node(dict_t *d, struct RandomListNode *t)
{
    struct RandomListNode *ret;

    if (t == NULL) {
        return NULL;
    } else {
        ret = dict_get(d, t);
        /* No existing records in the dict. */
        if (ret != NULL) {
            return ret;
        } else {
            ret = (struct RandomListNode *) malloc(sizeof(*ret));
            if (ret) {
                ret->label = t->label;
                dict_add(d, t, ret);
            }
            return ret;
        }
    }
}
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    dict_t *visited;
    struct RandomListNode *cur;
    struct RandomListNode dummy, *rear;

    visited = dict_new(hash, NULL);
    cur = head;
    dummy.next = NULL;
    rear = &dummy;
    while (cur) {
        rear->next = get_list_node(visited, cur);
        rear = rear->next;
        rear->random = get_list_node(visited, cur->random);
    }
    dict_free(visited);
    return dummy.next;
}

/* Approach 2: Iterative with O(1) space. */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode *cur;
    struct RandomListNode dummy, *rear, *new;

    cur = head;
    while (cur) {
        new = (struct RandomListNode *) malloc(sizeof(*new));
        if (new != NULL) {
            new->label = cur->label;
            new->next = cur->next;
            cur->next = new;
        }
        cur = new->next;
    }

    cur = head;
    while (cur) {
        cur->next->random = cur->random == NULL ? NULL : cur->random->next;
        cur = cur->next->next;
    }

    cur = head;
    dummy.next = NULL;
    rear = &dummy;
    while (cur) {
        rear->next = cur->next;
        rear = rear->next;
        cur->next = rear->next;
        cur = cur->next;
    }
    return dummy.next;
}