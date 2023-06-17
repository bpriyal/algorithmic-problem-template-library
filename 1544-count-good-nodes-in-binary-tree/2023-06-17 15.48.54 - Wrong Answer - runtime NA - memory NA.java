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
        Integer count = new Integer(0);
        dfs(root,new Integer(0), count);
        return count;
    }

    int dfs(TreeNode node, Integer max, Integer count){
        if(node != null){
            if(node.val > max){
                count++;
                max = node.val;
            }
            return dfs(node.left,max,count) + dfs(node.right,max,count);
        }
        return count;
    }
}