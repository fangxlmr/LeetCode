# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return None
        else:
            # Determine actual k here if k is lager than size of list
            size = self.getSize(head)
            k %= size

            if k == 0:
                return head
            else:
                # Find k-th node from the end of list
                fast = slow = head
                for _ in range(k):
                    fast = fast.next
                while fast:
                    sprev, fprev = slow, fast
                    slow, fast = slow.next, fast.next

                # Rotate list now
                sprev.next, fprev.next = None, head
                return slow

    def getSize(self, head: ListNode) -> int:
        count = 0
        while head:
            count += 1
            head = head.next
        return count