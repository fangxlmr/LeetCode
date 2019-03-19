# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        ohead, ehead = ListNode(0), ListNode(0)
        ohead.next, ehead.next = ehead, head
        ocur, ecur, cur = ohead, ehead, head

        while cur:
            ocur.next, ecur.next = cur, cur.next
            ocur, ecur = ocur.next, ecur.next
            cur = None if not cur.next else cur.next.next
        ocur.next = ehead.next
        return ohead.next
