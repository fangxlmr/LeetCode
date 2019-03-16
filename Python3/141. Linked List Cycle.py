# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        cur = head
        d = set()

        while cur:
            if cur in d:
                return True
            else:
                d.add(cur)
                cur = cur.next
        return False

    def hasCycle1(self, head):
        """
        :type head: ListNode
        :rtype: bool
        Two pointers solution
        """
        fast = slow = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                return True
        return False
