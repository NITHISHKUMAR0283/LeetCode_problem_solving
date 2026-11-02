# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def explore(self,root,p,q):
        if root==None:
            return None
        first = None
        second = None
        if root==p:
            first = root
            second = self.explore(root.left,p,q) or self.explore(root.right,p,q)
            
        elif root ==q:
            second = root
            first = self.explore(root.right,p,q) or self.explore(root.left,p,q)
        else:
            first = self.explore(root.left,p,q)
            second = self.explore(root.right,p,q)
        if first!=None and second!=None:
            return root
        elif first!=None:
            return first
        return second

        
    def lowestCommonAncestor(self, root, p, q):
        return self.explore(root,p,q)