class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        for i in range(len(nums)):
            if nums[i]!=nums[left]:                
                left+=1
                nums[left],nums[i] = nums[i],nums[left]
        return left+1
            