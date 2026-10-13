class Solution(object):
    def minSubArrayLen(self, target, nums):
        left = 0
        sum = 0
        n = len(nums)
        mini = float("inf")
        for right in range(n):
            sum+=nums[right]
            while left<n and sum>=target:                    
                mini = min(mini,right-left+1)
                sum-=nums[left]
                left+=1
        if mini==float("inf"):
            return 0
        return mini

