class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int

        """
        dp = [float("inf")]*(amount+1)
        dp[0]=0

        for i in range(1,amount+1):
            for coin in coins:
                needed = i-coin
                if needed>=0:
                    dp[i] = min(dp[i],dp[needed]+1)
        return dp[amount] if dp[amount]!=float("inf") else -1
        