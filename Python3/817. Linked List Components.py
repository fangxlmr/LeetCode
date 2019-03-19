# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def numComponents(self, head: ListNode, G: List[int]) -> int:
        count = 0
        isin = 0   # Flag of showing in or out of consecutive sublist
        d = set(G)

        while head:
            if head.val in d and isin == 0:
                count += 1
                isin = 1
            elif head.val not in d and isin == 1:
                isin = i
            head = head.next
        return count

    def numComponents1(self, head: ListNode, G: List[int]) -> int:
        count = 0
        cur = head
        d = set(G)
        while cur:
            if cur.val in d and getattr(cur.next, 'val', None) not in d:
                count += 1
            cur = cur.next
        return count
