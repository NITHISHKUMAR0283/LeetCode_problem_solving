class Solution(object):
    def maxDifference(self, nums):
        n = len(nums)
        dp = [0] * (n + 1)
        
        for i in range(n - 1, -1, -1):
            s1 = nums[i]
            if s1 % 3 == 0:
                lead1 = s1 - dp[i + 1]
            else:
                lead1 = s1 + dp[i + 1]
                
            if i + 1 < n:
                s2 = nums[i] + nums[i + 1]
                if s2 % 3 == 0:
                    lead2 = s2 - dp[i + 2]
                else:
                    lead2 = s2 + dp[i + 2]
                dp[i] = max(lead1, lead2)
            else:
                dp[i] = lead1
                
        return dp[0]