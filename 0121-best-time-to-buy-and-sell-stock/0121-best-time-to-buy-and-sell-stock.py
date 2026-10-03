class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        buyed = float("inf")
        profit = 0
        for ele in prices:
            profit = max(profit , ele-buyed)
            if ele<buyed:
                buyed = ele
        return profit