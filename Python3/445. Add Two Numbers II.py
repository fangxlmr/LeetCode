# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l1 = self.reverse(l1)
        l2 = self.reverse(l2)
        l1 = self.add(l1, l2)
        return self.reverse(l1)

    def add(self, l1: ListNode, l2: ListNode) -> ListNode:
        """
        Add two numbers that stored reversely in linked list
        """
        dummy = ListNode(0)
        prev = dummy
        carry = 0
        while l1 or l2:
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            summary = x + y + carry

            cur, carry = ListNode(summary % 10), summary // 10
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
            prev.next, prev = cur, cur

        if carry:
            cur = ListNode(carry)
            prev.next = cur

        return dummy.next

    def reverse(self, head: ListNode) -> ListNode:
        prev, cur = None, head
        while cur:
            cur.next, prev, cur = prev, cur, cur.next
        return prev

    def addTwoNumbers1(self, l1: ListNode, l2: ListNode) -> ListNode:
        len1 = len2 = 0
        cur1, cur2 = l1, l2
        while cur1:
            len1 += 1
            cur1 = cur1.next
        while cur2:
            len2 += 1
            cur2 = cur2.next
        if len1 < len2:
            head1, head2 = l2,  l1
        else:
            head1, head2 = l1, l2
        diff = abs(len1 - len2)

        l, carry = self.add(head1, head2, diff)
        if carry == 1:
            l, l.next = ListNode(carry), l
        return l

    def add(self, head1: ListNode, head2: ListNode, diff: int) -> (ListNode, int):
        if diff > 0:
            ans, carry = self.add(head1.next, head2, diff -1)
            sum = head1.val + carry
        elif head1 and head2:
            ans, carry = self.add(head1.next, head2.next, diff)
            sum = head1.val + head2.val + carry
        else:
            return None, 0

        num, carry = sum % 10, sum // 10
        new, new.next = ListNode(num), ans
        return new, carry

    def addTwoNumbers3(self, l1: ListNode, l2: ListNode) -> ListNode:
        num1 = num2 = 0
        cur1, cur2 = l1, l2

        while cur1:
            num1 = 10 * num1 + cur1.val
            cur1 = cur1.next
        while cur2:
            num2 = 10 * num2 + cur2.val
            cur2 = cur2.next
        num = num1 + num2
        ans = None
        while num > 0:
            ans, ans.next = ListNode(num % 10), ans
            num //= 10
        return ans if ans else ListNode(0)
