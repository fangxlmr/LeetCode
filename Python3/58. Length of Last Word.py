class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if not s:
            return 0
        else:
            words = s.split()
            return len(words[-1]) if words else 0
