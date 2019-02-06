class Solution:
    def threeSum(self, nums: 'List[int]') -> 'List[List[int]]':
        l = sorted(nums)
        d = set()
        l_len = len(l)
        for i in range(l_len - 2):
            left = i + 1
            right = l_len - 1
            while left < right:
                sums = l[i] + l[left] + l[right]
                if sums == 0:
                    d.add((l[i], l[left], l[right]))
                    left += 1
                elif sums < 0:
                    left += 1
                elif sums > 0:
                    right -= 1
                elif l[left] >= 0:
                    break
        return list(d)

