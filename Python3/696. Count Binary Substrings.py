class Solution:
#    def countBinarySubstrings(self, s: str) -> int:
#        """
#        Not so good.
#        """
#        ones = [x for x in s.split('0') if x]
#        zeros = [x for x in s.split('1') if x]
#
#        if s and s[0] == '1':
#            a = [min(len(zero), len(one)) for zero, one in zip(zeros, ones)]
#            ones.pop(0)
#            b = [min(len(zero), len(one)) for zero, one in zip(zeros, ones)]
#        else:
#            a = [min(len(zero), len(one)) for zero, one in zip(zeros, ones)]
#            zeros.pop(0)
#            b = [min(len(zero), len(one)) for zero, one in zip(zeros, ones)]
#
#        return sum(a) + sum(b)

#    def countBinarySubstrings(self, s):
#        """
#        Official solution: Group by character
#        """
#        groups = [1]
#        for i in range(1, len(s)):
#            if s[i-1] != s[i]:
#                groups.append(1)
#            else:
#                groups[-1] += 1
#
#        ans = 0
#        for i in range(1, len(groups)):
#            ans += min(groups[i-1], groups[i])
#        return ans

    def countBinarySubstrings(self, s):
        """
        Official solution: Linear scan
        Optimized approach #1
        """
        ans, prev, cur = 0, 0, 1
        for i in range(1, len(s)):
            if s[i-1] != s[i]:
                ans += min(prev, cur)
                prev, cur = cur, 1
            else:
                cur += 1

        return ans + min(prev, cur)
