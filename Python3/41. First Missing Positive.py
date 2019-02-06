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
