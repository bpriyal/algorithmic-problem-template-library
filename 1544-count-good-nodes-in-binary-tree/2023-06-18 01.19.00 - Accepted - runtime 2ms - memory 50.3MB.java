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
        return helper(root,root.val);
    }
    int helper(TreeNode node, int max){
        int count = 0;
        if (node != null){
            if(node.val >= max){
                max = node.val;
                ++count;
            }
            count += helper(node.left,max) + helper(node.right,max);
        }
        return count;
    }
}