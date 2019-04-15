class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        ans = []
        for word in [w for w in words if len(w) == len(pattern)]:
            p = {}
            seen = set()
            ok = 1
            for cp, cw in zip(pattern, word):
                if cp not in p and cw not in seen:
                    p[cp] = cw
                    seen.add(cw)
                elif p.get(cp, None) == cw:
                    continue
                else:
                    ok = 0
                    break
            if ok:
                ans.append(word)
        return ans
