# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        prev = dummy
        carry = 0
        while l1 or l2:
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            summary = x + y + carry

            cur, carry = ListNode(summary % 10), summary // 10
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
            prev.next, prev = cur, cur

        if carry:
            cur = ListNode(carry)
            prev.next = cur

        return dummy.next
