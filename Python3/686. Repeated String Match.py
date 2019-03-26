class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        lena, lenb = len(A), len(B)
        # Max repeated times
        n = lenb // lena
        for i in range(3):
            if (A * (n + i)).find(B) != -1:
                return n + i
        return -1
