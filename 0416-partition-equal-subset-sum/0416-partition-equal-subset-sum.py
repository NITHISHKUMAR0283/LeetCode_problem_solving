class Solution(object):
    def explore(self,nums,i,sum,target,dp):
        if i>=len(nums):
            return False
        if sum==target:
            return True
        if sum>target:
            return False
        if dp[i][sum]!=-1:
            return dp[i][sum]
        take = self.explore(nums,i+1,sum+nums[i],target,dp)
        nottake = self.explore(nums,i+1,sum,target,dp)
        dp[i][sum]=take or nottake
        return take or nottake

    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        sums = sum(nums)
        if sums%2==1:
            return False
        target = sums/2
        n = len(nums)
        dp = [[-1]*(target+1) for _ in range(n)]

        return self.explore(nums,0,0,target,dp)
        