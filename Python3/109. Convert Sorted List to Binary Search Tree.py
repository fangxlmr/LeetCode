# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        a = []
        while head:
            a.append(head.val)
            head = head.next
        def toBST(l: int, r: int) -> TreeNode:
            if l > r:
                return None
            else:
                mid = (l + r) // 2
                node = TreeNode(a[mid])
                if l == r:
                    return node
                else:
                    node.left = toBST(l, mid - 1)
                    node.right = toBST(mid + 1, r)
                    return node
        return toBST(0, len(a) - 1)

