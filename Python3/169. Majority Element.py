class Solution:
    def majorityElement(self, nums: 'List[int]') -> 'int':
        d = {}
        for item in nums:
            if item in d:
                d[item] += 1
            else:
                d[item] = 1
        l = sorted(d.items(), key=lambda items: items[1])
        return l[-1][0]
        # OR this is more handy
        # nums.sort()
        # return nums[len(nums) // 2]

