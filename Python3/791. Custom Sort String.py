from collections import Counter
class Solution:
    def customSortString(self, S: str, T: str) -> str:
        count = Counter(T)
        ordered = []
        for c in S:
            if count.get(c, None):
                ordered.append(c * count[c])
                count.pop(c)
        for c, n in count.items():
            ordered.append(c * count[c])
        return ''.join(ordered)
