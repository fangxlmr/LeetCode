class Solution:
    def judgeCircle(self, moves: str) -> bool:
        u, d = moves.count('U'), moves.count('D')
        l, r = moves.count('L'), moves.count('R')

        return u == d and l == r
