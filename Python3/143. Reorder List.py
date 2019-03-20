# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head:
            return
        else:
            slow = fast = head
            while fast and fast.next:
                slow, fast = slow.next, fast.next.next
            lhead, rhead = head, self.reverse(slow.next)
            slow.next = None
            lcur, rcur = lhead, rhead
            while lcur and rcur:
                tmp, rcur = rcur, rcur.next
                tmp.next = lcur.next
                lcur.next, lcur = tmp, lcur.next

    def reverse(self, head: ListNode) -> ListNode:
        if not head:
            return None
        else:
            prev, cur = None, head
            while cur:
                cur.next, cur, prev = prev, cur.next, cur
            return prev