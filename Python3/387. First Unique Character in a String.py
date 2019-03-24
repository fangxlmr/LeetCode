class Solution:
#    def firstUniqChar(self, s: str) -> int:
#        # If I use d = {c: s.count(c) for c in s} to init dict,
#        # then that will cause time limited exceeded
#        d = {}
#        for i, c in enumerate(s):
#            if c in d:
#                d[c] += 1
#            else:
#                d[c] = 1
#        for i, c in enumerate(s):
#            if d[c] == 1:
#                return i
#        return -1

    def firstUniqChar(self, s):
        """
        Official solution with a built-in module: collections
        """
        # build hash map : character and how often it appears
        count = collections.Counter(s)

        # find the index
        index = 0
        for ch in s:
            if count[ch] == 1:
                return index
            else:
                index += 1
        return -1
