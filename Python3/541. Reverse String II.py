class Solution:
#    def reverseStr(self, s: str, k: int) -> str:
#        groups = []
#        i = 0
#        while i + k - 1 < len(s):
#            groups.append(s[i: i + k])
#            i += k
#        groups.append(s[i:])
#        for index, group in enumerate(groups[:]):
#            if index % 2 == 0:
#                groups[index] = group[::-1]
#
#        return ''.join(groups)

    def reverseStr(self, s, k):
        # Better coding style from official solution
        a = list(s)
        for i in range(0, len(a), 2 * k):
            # Remember: list can modified this way
            a[i: i+k] = reversed(a[i: i+k])
        return "".join(a)
