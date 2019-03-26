class Solution:
    # def isPalindrome(self, s: str) -> bool:
    #     chars = ''.join([c.lower() for c in s if c.isalnum()])
    #     return chars == chars[::-1]

    def isPalindrome(self, s: str) -> bool:
        s = s.replace(' ', '')
        s = s.lower()
        # Use translate function
        s = s.translate(str.maketrans('', '', string.punctuation))
        return s == s[::-1]
