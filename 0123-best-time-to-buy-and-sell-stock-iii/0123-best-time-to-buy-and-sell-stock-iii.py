class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        dp = [[[-1 for _ in range(2)] for k in range(3)]for m in range(n)]
        max_profit = self.explore(prices,1,0,dp,0)
        return max_profit

    def explore(self,prices,canbuy,transactions,dp,i):
        if transactions>=2 or i>=len(prices):
            return 0
        if dp[i][transactions][canbuy]!=-1:
            return dp[i][transactions][canbuy]
        buy = float("-inf")
        if canbuy==1:
            buy = self.explore(prices,0,transactions,dp,i+1)-prices[i]
            
        sell = float("-inf")
        if canbuy==0:
            sell = self.explore(prices,1,transactions+1,dp,i+1)+prices[i]

        hold = self.explore(prices,canbuy , transactions,dp,i+1)
        dp[i][transactions][canbuy]= max(buy,max(sell,hold))
        return dp[i][transactions][canbuy]
        