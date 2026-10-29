class Solution(object):
    def maxProfit(self, prices):
        
        dp = [[0]*3 for _ in range(2)]
        n = len(prices)

        for i in range(n-1,-1,-1):
            next = [[0]*3 for _ in range(2)]
            for trans in range(2):
                next[0][trans] = max(dp[0][trans],dp[1][trans]-prices[i])
                next[1][trans] = max(dp[1][trans],dp[0][trans+1]+prices[i])
            
            dp = next
        return dp[0][0]
