class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        say = "1"
        for i in range(n - 1):
            count = say
            say = ""
            p = count[0]
            ctr = 0
            for c in count:
                if p == c:
                    ctr += 1
                else:
                    say += str(ctr) + p
                    ctr = 1
                    p = c
            say += str(ctr) + p
        return say

