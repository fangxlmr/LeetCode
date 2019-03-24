import collections


class Solution:
#    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
#        # build hashmap: char and how often it appears
#        count = collections.Counter(magazine)
#
#        for c in ransomNote:
#            if count.get(c) is None or count[c] == 0:
#                return False
#            count[c] -= 1
#        return True

    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        # More clean and elegant
        for i in set(ransomNote):
            if ransomNote.count(i) > magazine.count(i):
                return False
        return True