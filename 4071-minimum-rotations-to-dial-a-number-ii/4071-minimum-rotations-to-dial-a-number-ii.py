class Solution(object):
    def operation (self,current,next):
        diff = abs(current-next)
        return  min(diff,10-diff)     

    def minRotations(self, n, s):
        """
        :type n: int
        :type s: str
        :rtype: int
        """
        costRev = 0
        dp = [0]*len(s)
        for i in range(len(s)-1,0,-1):
            
            current = int(s[i])
            next =int(s[i-1])
            costRev+=self.operation(current,next)                  
            
            dp[i]=costRev
        costFront = 0
        current = 0
        Mincost = float("inf")
        for i in range(len(s)-1):
            
            this = self.operation(current,next)
            Mincost = min(Mincost,dp[i+1]+self.operation(current,int(s[-1]))+costFront)
            next = int(s[i])
            costFront+=self.operation(current,next)
            current = int(s[i])
        Mincost =min(Mincost,costFront+self.operation(current,int(s[-1])))

        return Mincost