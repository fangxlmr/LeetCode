class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums = []
        nums.extend(nums1)
        nums.extend(nums2)
        nums.sort()
        length = len(nums)
        mid = length // 2

        if length & 1:
            return nums[mid]
        else:
            return (nums[mid] + nums[mid - 1]) / 2

