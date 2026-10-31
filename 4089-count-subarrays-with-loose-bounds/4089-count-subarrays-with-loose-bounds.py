class Solution(object):
    def countSubarrays(self, nums, minK, maxK):
        
        left = 0
        n = len(nums)
        count = 0
        for i in range(n):
            if nums[i]>maxK or nums[i]<minK:
                left = i+1
            else:
                count+=i-left+1
        return count
        