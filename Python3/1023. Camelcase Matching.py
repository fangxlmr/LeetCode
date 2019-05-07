class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        def match(query, pattern):
            i = j = 0
            while i < len(query) and j < len(pattern):
                if query[i] == pattern[j]:
                    i, j = i + 1, j + 1
                else:
                    if query[i].isupper():
                        return False
                    else:
                        i += 1
            return j == len(pattern) and (not query[i:] or query[i:].islower())
        return [match(query, pattern) for query in queries]
