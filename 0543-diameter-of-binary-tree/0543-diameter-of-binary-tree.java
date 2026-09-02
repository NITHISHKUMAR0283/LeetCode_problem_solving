/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int dfs(TreeNode root,int [] solution){
        int left= 0,right  = 0;
        if(root.left!=null)left = dfs(root.left,solution);
        if(root.right!=null)right = dfs(root.right,solution);
        solution [0] = Math.max(left+right,solution[0]);
        return 1+Math.max(left,right);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        int [] solution ={0};
        dfs(root,solution);
        return solution[0];
    }
}