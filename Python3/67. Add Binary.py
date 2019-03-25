class Solution:
    def addBinary(self, a: str, b: str) -> str:
        ba = bb = 0
        for i in a:
            ba = ba * 2 + int(i)
        for i in b:
            bb = bb * 2 + int(i)
        bc = ba + bb
        return bin(bc)[2:]