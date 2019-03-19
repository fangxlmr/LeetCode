# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
        cur, length = root, 0
        while cur:
            length += 1
            cur = cur.next
        quotient, remainder = length // k, length % k

        ans = []
        while root:
            if remainder > 0:
                count = quotient + 1
                remainder -= 1
            else:
                count = quotient
            ans.append(root)
            for _ in range(count - 1):
                root = root.next
            root.next, root = None, root.next

        ans_len = len(ans)
        for _ in range(k - ans_len):
            ans.append([])
        return ans

    def splitListToParts1(self, root: ListNode, k: int) -> List[ListNode]:
        """
        A better coding style.
        """
        cur = root
        for N in range(1001):
            if not cur:
                break
            else:
                cur = cur.next
        width, remainder = divmod(N, k)

        ans = []
        cur = root
        for i in range(k):
            head = cur
            for j in range(width + (i < remainder) - 1):
                if cur:
                    cur = cur.next
                else:
                    break
            if cur:
                cur.next, cur = None, cur.next
            ans.append(head)
        return ans
