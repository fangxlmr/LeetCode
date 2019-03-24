# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
#    def tree2str(self, t: TreeNode) -> str:
#        """
#        I could write in top function using string recursively,
#        but I assume that may cause a lot string object and make
#        GC working. So I chose to use list in a subfunction.
#        This need more time to run.
#        """
#        def t2s(root):
#            if not root:
#                return []
#            else:
#                root_str = [str(root.val)]
#                left_str = t2s(root.left)
#                right_str = t2s(root.right)
#
#            if left_str and right_str:
#                children_str = ['('] + left_str + [')('] + right_str + [')']
#            elif left_str and not right_str:
#                children_str = ['('] + left_str + [')']
#            elif not left_str and right_str:
#                children_str = ['()('] + right_str + [')']
#            else:
#                children_str = []
#
#            return root_str + children_str
#        return ''.join(t2s(t))

    def tree2str(self, t: 'TreeNode') -> 'str':
        """
        Copied from https://leetcode.com/submissions/detail/217176205/
        This teach me to focus on algorithm directly without thinking to much
        when using Python. Don't pay too much attention on optimizing code in
        language level instead algorithm level.
        """
        if t == None:
            return ""
        lans = '(' + self.tree2str(t.left) + ')'
        rans = '(' + self.tree2str(t.right) + ')'
        if lans == "()" and rans == "()":
            lans, rans = '', ''
        elif rans == "()":
            rans = ''

        return str(t.val) + lans + rans
