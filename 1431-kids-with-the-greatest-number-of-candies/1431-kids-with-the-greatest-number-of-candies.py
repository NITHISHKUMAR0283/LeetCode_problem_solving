class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        greatest = 0
        for ele in candies:
            greatest = max(greatest,ele)
        ans = [False]*len(candies)
        for i in range(len(candies)):
            if candies[i]+extraCandies>=greatest:
                ans[i]=True
        return ans

        