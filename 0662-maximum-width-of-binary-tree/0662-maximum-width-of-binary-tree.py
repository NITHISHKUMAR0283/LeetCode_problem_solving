# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def widthOfBinaryTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        res=float("-inf")
        que = deque([[root,0]])
        i=0
        while que:
            mini =float("inf")
            maxi = float("-inf")
            for  _ in range(len(que)):
                node = que.popleft()
                mini = min(mini,node[1])
                maxi = max(maxi,node[1])
                if node[0].left:
                    que.append([node[0].left,2*node[1]+1])
                if node[0].right:
                    que.append([node[0].right,2*node[1]+2])
            res=max(res,maxi-mini+1)
        return res
        