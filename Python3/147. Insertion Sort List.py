# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        dummy = ListNode(0)
        cur = head
        while cur:
            tmp = cur.next
            self.insert(dummy, cur)
            cur = tmp
        return dummy.next

    def insert(self, head: ListNode, node: ListNode) -> None:
        cur = head
        while cur.next and cur.next.val < node.val:
            cur = cur.next
        cur.next, node.next = node, cur.next

    def insertionSortList1(self, head: ListNode) -> ListNode:
        """
        Time Limit Exceeded
        """
        a = []
        cur = head
        while cur:
            a.append(cur.val)
        cur = head
        for item in sorted(a):
            cur.val = item
            cur = cur.next
        return head
