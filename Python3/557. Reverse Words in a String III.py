class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(' ')
        return ' '.join(word[-1::-1] for word in words)
