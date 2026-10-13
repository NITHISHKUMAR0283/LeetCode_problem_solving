class Solution(object):
    def maximumSubarraySum(self, nums, k):
        left = 0
        sum = 0
        n = len(nums)
        seen = set()
        maxi = float("-inf")
        for right in range(n):
            sum+=nums[right]
            while nums[right] in seen:
                seen.discard(nums[left])
                sum-=nums[left]
                left+=1
            if right-left+1==k:
                maxi = max(maxi,sum)
                sum -=nums[left]                
                seen.discard(nums[left])
                left+=1
            seen.add(nums[right])
        if maxi ==float("-inf"):
            return 0
        return maxi            