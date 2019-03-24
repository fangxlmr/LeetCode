class Solution:
    def romanToInt(self, s: str) -> int:
        d = {'I':1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        num = 0
        for i, c in enumerate(s):
            if i + 1 < len(s) and d[c] < d[s[i + 1]]:
                num -= d[c]
            else:
                num += d[c]
        return num
