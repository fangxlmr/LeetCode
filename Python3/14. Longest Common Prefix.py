class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # Vertical scanning according to official solution
        if not strs:
            return ""
        else:
            for i, c in enumerate(strs[0]):
                for s in strs:
                    if i >= len(s) or s[i] != c:
                        return strs[0][:i]
            return strs[0]
