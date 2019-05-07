class Solution:
    def countSubstrings(self, s: str) -> str:
        size = len(s)
        if size == 0:
            return 0
        else:
            dp = [[0 for x in range(size)] for y in range(size)]

            # Initialize dp array
            for i in range(size):
                dp[i][i] = 1

            for i in range(size - 1):
                if s[i] == s[i + 1]:
                    dp[i][i + 1] = 1

            # dp core
            for n in range(3, size + 1):
                for i in range(size - n + 1):
                    j = i + n - 1
                    if s[i] == s[j] and dp[i + 1][j - 1]:
                        dp[i][j] = 1

            return sum([sum(x) for x in dp])
