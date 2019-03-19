"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        cur = head
        while cur:
            if cur.child:
                tail = self.getTail(cur.child)
                tail.next = cur.next
                if cur.next:
                    cur.next.prev = tail
                cur.child.prev, cur.child, cur.next = cur, None, cur.child
            cur = cur.next
        return head

    def getTail(self, head: 'Node') -> 'Node':
        while head and head.next:
            head = head.next
        return head
