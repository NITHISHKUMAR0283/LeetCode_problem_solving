class Solution(object):
    def bfs(self,adj,start,visited):

        queue = deque()

        queue.append(start)
    
        while queue:
            
            source = queue.popleft()
            for v in adj[source]:
                if v in visited :
                    continue
                visited.add(v)
                queue.append(v)

    def makeConnected(self, n, connections):

        if len(connections)<n-1:
            return -1
        
        adj = defaultdict(list)



        for u,v in connections:
            adj[u].append(v)
            adj[v].append(u)
        
        visited = set()
        components = 0
        for comp in range(n):
            if comp not in visited:    
                visited.add(comp)
                self.bfs(adj,comp,visited) 
                components+=1
        if components ==1:
            return 0
        return components-1