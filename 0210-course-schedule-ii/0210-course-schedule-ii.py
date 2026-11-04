class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        queue = []
        n = numCourses
        adjacency = [[0]*n for _ in range(n)]

        pre = [0]*n
        for (u,v) in prerequisites:
            adjacency[v][u] = 1
            pre[u]+=1
        
        result = []
        for i in range(n):
            if pre[i] ==0:
                queue.append(i)
        while len(queue)>0:
            for _ in range(len(queue)):
                free = queue.pop()
                result.append(free)
                for v in range(n):
                    if adjacency[free][v]==0:
                        continue
                    pre[v]-=1
                    if pre[v]==0:
                        queue.append(v)
        if len(result)==n:
            return result
        return []