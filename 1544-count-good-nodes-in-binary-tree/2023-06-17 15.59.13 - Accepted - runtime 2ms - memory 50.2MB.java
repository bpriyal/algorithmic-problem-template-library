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
    public int goodNodes(TreeNode root) {
        return helper(root,root.val,0);
    }

    int helper(TreeNode node, int max, int count){
        while(node != null){
            if(node.val >= max){
                max = node.val;
                count++;
            }
            //count += helper(node.left,max,count) + helper(node.right,max,count);
            count = helper(node.left,max,count);
            count = helper(node.right,max,count);
            return count;
        }
        return count;
    }
}