class Solution:
#    def reverseOnlyLetters(self, S: str) -> str:
#        """
#        Looks not so good and clean.
#        """
#        s = list(S)
#        t = [x for x in S[::-1] if x.isalpha()]
#        index = 0
#        for i, c in enumerate(s):
#            if c.isalpha():
#                s[i] = t[index]
#                index += 1
#        return ''.join(s)

    def reverseOnlyLetters(self, S):
        """
        Official solution is more clean and precise.
        """
        letters = [c for c in S if c.isalpha()]
        ans = []
        for c in S:
            if c.isalpha():
                ans.append(letters.pop())
            else:
                ans.append(c)
        return "".join(ans)
