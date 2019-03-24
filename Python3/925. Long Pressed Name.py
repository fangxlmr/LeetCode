class Solution:
#    def isLongPressedName(self, name: str, typed: str) -> bool:
#        if len(typed) < len(name):
#            return False
#        else:
#            i = j = 0
#            while i < len(name) and j < len(typed):
#                if name[i] == typed[j]:
#                    print(name[i], typed[j])
#                    i += 1
#                    j += 1
#                elif i > 0 and name[i - 1] == typed[j]:
#                    print(name[i], typed[j])
#                    j += 1
#                else:
#                    return False
#            return i == len(name) and typed[j:] == name[-1]*(len(typed) - j)

    def isLongPressedName(self, name, typed):
        # Copied from solution: https://leetcode.com/submissions/detail/217235875/
        # A better coding style
        i = 0
        for j in range(len(typed)):
            if i < len(name) and name[i] == typed[j]:
                i += 1
                # Comparing with typed[j - 1] is more genius
            elif j == 0 or typed[j] != typed[j - 1]:
                return False
        return i == len(name)
