class Solution:
    # def repeatedSubstringPattern(self, s: str) -> bool:
    #     if not s:
    #         return True
    #     else:
    #         indexes = [i for i, c in enumerate(s) if c == s[0]]
    #         for index in indexes:
    #             try:
    #                 splited = s.split(s[:index])
    #                 if not all(splited):
    #                     return True
    #             except ValueError:
    #                 continue
    #         return False
    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in (s + s)[1:-1]