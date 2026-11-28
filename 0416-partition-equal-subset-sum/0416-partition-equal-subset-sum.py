class Solution(object):
    def canPartition(self, nums):
        total = sum(nums)
        if total%2!=0:
            return False
        target = total/2

        n = len(nums)

        dp = [False for _ in range(total+1)] 
        
        dp[0]=True
        dp[nums[0]]=True
        for i in range(1,n):
            for j in range(target,-1,-1):
                need = j-nums[i]
                if dp[need]:
                    dp[j]=True
        return dp[target]
