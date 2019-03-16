# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        fast = slow = head
        # Find middle node of the list
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        # Reverse the other half
        prev, slow = slow, slow.next if slow else None
        while slow:
            prev, slow.next, slow = slow, prev, slow.next
        cur1, cur2 = head, prev
        while cur1 and cur2:
            if cur1.val != cur2.val:
                return False
            if cur1 is cur2 or cur1.next is cur2:
                return True
            cur1, cur2 = cur1.next, cur2.next
        return True

    def isPalindrome1(self, head: ListNode) -> bool:
        values = []
        while head:
            values.append(head.val)
            head = head.next

        return values == values[::-1]
