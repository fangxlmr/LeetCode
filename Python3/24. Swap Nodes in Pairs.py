# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy, dummy.next = ListNode(0), head
        prev, cur = dummy, head

        while cur and cur.next:
            tmp = cur.next.next
            cur.next.next, cur.next, prev.next = cur, tmp, cur.next
            prev, cur = prev.next.next, tmp
        return dummy.next

