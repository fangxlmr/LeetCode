class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        n1 = n2 = 0
        for i in num1:
            n1 = n1 * 10 + int(i)
        for i in num2:
            n2 = n2 * 10 + int(i)
        n = n1 + n2
        return str(n)
