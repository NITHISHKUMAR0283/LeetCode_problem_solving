class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        n = len(temperatures)
        ans = [0] * n

        stack = []

        for i in range(n):
            while len(stack)>0 and stack[-1][0]<temperatures[i]:
                val,ind = stack.pop()
                ans[ind] = i-ind
            stack.append((temperatures[i],i))
        return ans