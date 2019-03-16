# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy, dummy.next = ListNode(0), head
        prev = dummy
        while head:
            if head.val == val:
                prev.next, head = head.next, head.next
            else:
                prev, head = head, head.next
        return dummy.next