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
    public int pathSum(TreeNode root, int targetSum) {
        TreeNode node = root;
        int count = dfs(node,targetSum);       
        return count;
    }

    int dfs(TreeNode node, int target){
        int count = 0;
        if(node != null){
            count = helper(node,0,0,target);
            count += dfs(node.left,target);
            count += dfs(node.right,target);
        }
        return count;
    }

    int helper(TreeNode node, int total, int count, int target){
        if(node != null){
            total += node.val;
            if(total == target){
                count++;
            }
            count = helper(node.left,total,count,target);
            count = helper(node.right,total,count,target);
        }
        return count;       
    }
}