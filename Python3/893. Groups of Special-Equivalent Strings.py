class Solution:
    def numSpecialEquivGroups(self, A: List[str]) -> int:
        """
        I understand the problem, but no proper solution afterward.
        This solution copied from LeetCode.com is so genius.
        """
#         def count(A):
#             ans = [0] * 52
#             for i, letter in enumerate(A):
#                 ans[ord(letter) - ord('a') + 26 * (i%2)] += 1
#             print(tuple(ans))
#             return tuple(ans)

#         return len({count(word) for word in A})

        return len({"".join(sorted(s[0::2])) + "".join(sorted(s[1::2])) for s in A})
