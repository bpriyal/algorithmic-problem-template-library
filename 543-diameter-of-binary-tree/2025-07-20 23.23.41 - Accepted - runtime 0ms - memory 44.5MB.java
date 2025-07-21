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
    int MAX = Integer.MIN_VALUE;
    public int diameterOfBinaryTree(TreeNode root) {
        helper (root);
        return MAX;
    }

    int helper (TreeNode root) {
        if (root == null) return 0;
        int l = helper (root.left);
        int r = helper (root.right);
        MAX = Math.max (MAX, l + r);
        return Math.max (l + 1, r + 1);
    }
}