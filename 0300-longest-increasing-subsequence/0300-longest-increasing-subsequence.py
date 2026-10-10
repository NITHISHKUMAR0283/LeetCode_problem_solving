class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        dp = [1 for _ in range(n)]
        dp[0]=1
        for i in range(n):
            for j in range(0,i+1):
                
                if nums[j]<nums[i]:
                    dp[i]=max(dp[i],1+dp[j])
        return max(dp)



