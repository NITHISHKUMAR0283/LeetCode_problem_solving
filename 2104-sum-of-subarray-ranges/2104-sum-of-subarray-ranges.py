class Solution(object):
    def subArrayRanges(self, nums):
        ranges = 0
        for i in range(len(nums)):
            smallest = nums[i]
            greatest = nums[i]
            for j in range(i,len(nums)):
                if nums[j]<smallest:
                    smallest=nums[j]
                if nums[j]>greatest:
                    greatest= nums[j]
                ranges += greatest-smallest
        return ranges