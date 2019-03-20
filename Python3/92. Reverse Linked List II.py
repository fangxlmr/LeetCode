# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
        def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
            # Locate m-th node
            dummy, dummy.next = ListNode(-1), head
            prev, cur = dummy, head
            for _ in range(m - 1):
                prev, cur = cur, cur.next

            # Reverse nodes from m-th to n-th
            tmp, prev, cur = prev, cur, cur.next
            for _ in range(n - m):
                cur.next, cur, prev = prev, cur.next, cur
            tmp.next.next, tmp.next = cur, prev
            return dummy.next
