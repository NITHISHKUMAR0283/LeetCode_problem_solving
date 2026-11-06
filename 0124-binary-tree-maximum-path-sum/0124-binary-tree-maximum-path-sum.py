# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def explore(self,root,result):
        if root==None:
            return 0
        if root.left ==None and root.right==None:
            result[0] = max(result[0],root.val)
            return root.val
        left = max(0,self.explore(root.left,result))
        right = max(0,self.explore(root.right,result))
        result[0] = max(result[0],max(left+right+root.val,max(left+root.val,right+root.val)))
        return max(left,right)+root.val

    def maxPathSum(self, root):
        result = [root.val]
        self.explore(root,result)
        return result[0]
        