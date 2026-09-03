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
    public int dfs(TreeNode node,int [] solution){
        if(node==null)return 0;
        int left = Math.max(0,dfs(node.left,solution));
        int right = Math.max(0,dfs(node.right,solution));
        solution [0] = Math.max(left+right+node.val,solution[0]);
        return Math.max(left,right)+node.val;
    }
    public int maxPathSum(TreeNode root) {  
        int [] solution = {root.val};
        dfs(root,solution);
        return solution[0];
        
    }
}