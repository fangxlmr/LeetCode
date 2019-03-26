class Solution:
    # def validPalindrome(self, s: str) -> bool:
    #     i, j = 0, len(s) - 1
    #     while i < j:
    #         if s[i] != s[j]:
    #             break
    #         else:
    #             i += 1
    #             j -= 1
    #     if i >= j:
    #         return True
    #     else:
    #         s1 = s[:i] + s[i + 1:]
    #         s2 = s[:j] + s[j + 1:]
    #         return s1 == s1[::-1] or s2 == s2[::-1]

    def validPalindrome(self, s):
        # Official solution is more clean
        def is_pali_range(i, j):
            # This is tricky
            return all(s[k] == s[j - k + i] for k in range(i, j))

        for i in range(len(s) // 2):
            # This is tricky
            if s[i] != s[~i]:
                j = len(s) - 1 - i
                return is_pali_range(i + 1, j) or is_pali_range(i, j - 1)
        return True
