class Solution(object):
    def maxScore(self, parent, op, score):
        
        n = len(parent)
        adj = [[] for _ in range(n)]

        for v in range(1,n):
            u = parent[v]
            adj[u].append(v)
        order = [0]
        for u in order:
            for v in adj[u]:
                order.append(v)
        curr = n-1
        dp = [0 ]*n
        for curr in reversed(order):
            if not adj[curr]:
                dp[curr] = score[curr]
                continue
            
            sum = score[curr]
            mini = float("inf")
            for v in adj[curr]:
                sum+=dp[v]
                mini = min(mini,dp[v])
            if mini<0 and op[curr]==0:
                sum-=mini
            elif op[curr]==1:
                sum-=mini
            dp[curr]=sum
        return dp[0]
