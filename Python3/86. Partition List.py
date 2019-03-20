# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        smaller, greater = ListNode(0), ListNode(0)
        stail, gtail = smaller, greater
        cur = head
        while cur:
            if cur.val < x:
                stail.next, stail = cur, cur
            else:
                gtail.next, gtail = cur, cur
            cur = cur.next
        stail.next, gtail.next = greater.next, None
        return smaller.next

