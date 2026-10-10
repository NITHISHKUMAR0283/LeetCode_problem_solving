class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        next = 0
        current = 0
        n = len(nums)
        while current<n:
            if nums[current]!=val:
                nums[next],nums[current] = nums[current],nums[next]
                next+=1
                current+=1
            else:
                
                current+=1
        return next