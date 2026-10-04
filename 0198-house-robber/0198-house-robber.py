class Solution(object):
    def rob(self, nums):
        dp = [0 for _ in range(len(nums)+1)]        
        ans = 0
        for i in range(len(nums)):
            if i==2 :
                dp[i]=nums[0]
            if i>2:
                dp[i]=max(dp[i-2],dp[i-3])
            dp[i]+=nums[i]
            ans = max(ans,dp[i])
        return max(dp)