class Solution(object):
    def canPartition(self, nums):
        total = sum(nums)
        if total%2!=0:
            return False
        target = total/2

        n = len(nums)

        dp = [[False for _ in range(total+1)] for _ in range(n)]
        
        dp[0][0]=True
        dp[0][nums[0]]=True

        for i in range(1,n):
            for j in range(0,target+1):
                dp[i][j] = dp[i-1][j]
                need = j-nums[i]
                if need<0:
                    continue
                if dp[i-1][need]==True:
                    dp[i][j]=True

        return dp[n-1][target]
