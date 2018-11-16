/* Approach 1: Cycle detection.
 * We can solve this problem just like detect a cycle in
 * linked list.
 * However, it's really hard to figure out this solution cause
 * it's kind of anti-intuition. Normally, we could solve this by
 * set or sorted array.
 */
int findDuplicate(int* nums, int numsSize) {
    int slow, fast;

    slow = fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    int ptr1 = nums[0];
    int ptr2 = nums[slow];
    while (ptr1 != ptr2) {
        ptr1 = nums[ptr1];
        ptr2 = nums[ptr2];
    }
    return ptr1;
}