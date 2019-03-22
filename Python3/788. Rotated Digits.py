class Solution:
#    def rotatedDigits(self, N: int) -> int:
#        """
#        Not so good.
#        """
#        invalid = set("347")
#        valid = set("0125689")
#        good = set("2569")
#        count = 0
#        for i in range(1, N + 1):
#            s = set(str(i))
#            if (s - valid) and (s - valid) <= invalid:
#                continue
#            elif s & good:
#                count += 1
#        return count

    def rotatedDigits(self, N):
        """
        Better coding style from https://leetcode.com/problems/rotated-digits/discuss/116519/Python-solution
        """
        def isValidRotation(num):
            return (not any(s in {'3', '4', '7'} for s in num)) and any(s in {'2', '5', '6', '9'} for s in num)

        return sum([isValidRotation(str(i)) for i in range(1, N + 1)])
