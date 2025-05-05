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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> output = new LinkedList();
        helper (root, output);
        return output;
    }
    
    private void helper (TreeNode node, List<Integer> o) {
        if (node == null) return;
        helper (node.left, o);
        helper (node.right, o);
        o.add (node.val);
    }
}