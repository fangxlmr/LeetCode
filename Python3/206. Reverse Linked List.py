# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev, cur = None, head

        while cur:
            prev, cur.next, cur = cur, prev, cur.next
            
        return prev
