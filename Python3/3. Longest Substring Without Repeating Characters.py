class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = {}
        left = max_len = 0
        for right, c in enumerate(s):
            if c in d:
                left = max(left, d.get(c) + 1)
            max_len = max(max_len, right - left + 1)
            d[c] = right
        return max_len
