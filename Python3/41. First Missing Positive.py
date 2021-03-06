class Solution:
    def firstMissingPositive(self, nums: 'List[int]') -> 'int':
        '''
        Not meet requirement of O(n) time complexity
        '''
        dummy = [item for item in nums if item > 0]
        dummy = list(set(dummy))
        dummy.sort()
        item = 0
        for index, item in enumerate(dummy):
            if index + 1 != item:
                return index + 1
        return item + 1


class Solution:
    def firstMissingPositive(self, nums: 'List[int]') -> 'int':
        n = len(nums)
        for i in range(n):
            while 0 < nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]

        for i, _ in enumerate(nums):
            if nums[i] - 1 != i:
                return i + 1
        return n + 1
