"""
# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
"""


class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        cur = head
        # Copy node
        while cur:
            new = ListNode(cur.val)
            new.next, cur.next, cur = cur.next, new, cur.next

        # Copy random pointers
        cur = head
        while cur:
            cur.next.random = cur.random.next if cur.random else None
            cur = cur.next.next

        # Split them and generate a deep copy
        dummy = ListNode(-1)
        tail = dummy
        cur = head
        while cur:
            tail.next, tail = cur.next, cur.next
            cur.next = cur.next.next
            cur = cur.next
        tail.next = None
        return dummy.next
