class Solution(object):
    def operation (self,current,next):
        # function which return min rotation needed reach current from next
        diff = abs(current-next)
        return  min(diff,10-diff)    
         

    def minRotations(self, n, s):
        """
        :type n: int
        :type s: str
        :rtype: int
        """
        costRev = 0
        dp = [0]*len(s) # dp stores cost of rotation from backward
        nums = [int(x) for x in s] # convertion to integer array 
        for i in range(len(s)-1,0,-1):
            
            current = nums[i]
            next =nums[i-1]
            costRev+=self.operation(current,next)                  
            
            dp[i]=costRev
        costFront = 0
        current = 0
        Mincost = float("inf")
        for i in range(len(s)-1):
            # using the dp we can find simulated overall cost
            Mincost = min(Mincost,dp[i+1]+self.operation(current,nums[-1])+costFront)
            next = nums[i]
            costFront+=self.operation(current,next)
            current = nums[i]

        Mincost =min(Mincost,costFront+self.operation(current,nums[-1])) # hardcore calculation of last rotation since the for loop cant cover the last rotation 

        return Mincost