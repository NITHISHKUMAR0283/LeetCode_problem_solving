
class Solution(object):
    def explore(self,root,x,y,vertical,left,right,max_len,depth):
        if root==None:
            return
        if y<left[0]:
            left[0] = y
        elif y>right[0]:
            right[0] = y
        if depth[0]<x:
            depth[0]=x
        
        if y not in vertical:
            vertical[y]={}
        if x not in vertical[y]:
            vertical[y][x]=[]
        vertical[y][x].append(root.val)
        max_len[0] = max(max_len[0],len(vertical[y][x]))
                
        self.explore(root.left,x+1,y-1,vertical,left,right,max_len,depth)
        self.explore(root.right,x+1,y+1,vertical,left,right,max_len,depth)

    def verticalTraversal(self, root):
        vertical = {}
        left = [0]
        right=[0]
        max_len = [0]
        depth = [0]
        self.explore(root,0,0,vertical,left,right,max_len,depth)
        result = []
        for i in range(left[0],right[0]+1):
            curr = []
            for j in range(depth[0]+1):
                if j in vertical[i]:
                    vertical[i][j].sort()
                    curr+=vertical[i][j]
            result.append(curr)
        return result



