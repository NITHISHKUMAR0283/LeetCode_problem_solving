class Solution(object):
    def bfs(self,si,sj,grid):
        
        direction = {(0,1),(0,-1),(1,0),(-1,0)}
        queue = [(si,sj)]
        n = len(grid)
        m = len(grid[0])
        while len(queue)>0:
            for _ in range(len(queue)):
                (i,j) = queue.pop()
                for ni,nj in direction:
                    ti,tj = i+ni,j+nj
                    if ti>=0 and ti<n and tj>=0 and tj<m and  grid[ti][tj]=="1":
                        grid[ti][tj]="-1"
                        queue.append((ti,tj))

    def numIslands(self, grid):

        islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]=="1":
                    self.bfs(i,j,grid)
                    islands+=1
        return islands