# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        dummy, dummy.next = ListNode(0), head
        prev, cur = dummy, head
        dup = False
        while cur:
            if cur.next and cur.val == cur.next.val:
               dup = True
               cur.next = cur.next.next
            else:
                if dup is True:
                    prev.next, cur = cur.next, cur.next
                    dup = False
                else:
                    prev, cur = cur, cur.next
        return dummy.next