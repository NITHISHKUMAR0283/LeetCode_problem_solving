# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def inorder(self,root,d,result):
        if root ==None:
            return
        self.inorder(root.left,d+1,result)        
        result[d]=root.val
        self.inorder(root.right,d+1,result)
    def rightSideView(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        result = [None]*100

        self.inorder(root,0,result)
        i = 0
        while result[i]!=None and i<100:
            i+=1
        return result [:i]