# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        lena, lenb = 0, 0
        cura, curb = headA, headB
        # Find len of each list
        while cura:
            lena += 1
            cura = cura.next
        while curb:
            lenb += 1
            curb = curb.next

        # Determin longer list
        if lena > lenb:
            cura, curb = headA, headB
        else:
            cura, curb = headB, headA
        diff = abs(lena - lenb)
        for _ in range(diff):
            cura = cura.next

        while cura and curb and cura is not curb:
            cura, curb = cura.next, curb.next

        return cura
