class Solution(object):
    def bfs(self,heights,success,queue):
        m = len(heights)
        n = len(heights[0])

        directions = [(0,1),(0,-1),(1,0),(-1,0)]
        
        result = []
        while queue:
            for k in range(len(queue)):
                si,sj = queue.popleft()
                success.add((si,sj))
                for ni,nj in directions:
                    i , j = ni+si , nj+sj
                    if 0<=i<m and 0<=j<n and heights[si][sj]<=heights[i][j] and (i,j) not in success:
                        queue.append((i,j))
        

    def pacificAtlantic(self, heights):
        
        m = len(heights)
        n = len(heights[0])
        pr = set()
        ar = set()
        queue= deque()
        for i in range(m):
            queue.append((i,0))
        for j in range(n):
            queue.append((0,j))

        self.bfs(heights,pr,queue)
        queue = deque()
        for i in range(m):
            queue.append((i,n-1))
        for j in range(n):
            queue.append((m-1,j))
        self.bfs(heights,ar,queue)
        return list(pr & ar)