class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        dp = [[0]*(1+k) for _ in range(2)]
        for i in range(k+1):
            dp[1][i]=-float("inf")

        for price in prices:
            next_dp = [[0]*(1+k) for _ in range(2)]

            for transaction in range(k+1):
                next_dp[1][transaction]=max(dp[1][transaction],dp[0][transaction]-price)
                if transaction!=k:
                    next_dp[0][transaction]=max(dp[0][transaction],dp[1][transaction+1]+price)
            dp=next_dp
        return max(dp[0])
