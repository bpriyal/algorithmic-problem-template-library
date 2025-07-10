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
    int max = 0;
    public int longestZigZag(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) return 0;
        int val = Math.max(helper(root.left, true), helper(root.right, false));
        return Math.max(val, max);
    }

    int helper (TreeNode root, boolean isLeftChild) {
        if (root == null) return 0;
        int l = helper (root.left, true);
        int r = helper (root.right, false);
        max = Math.max (Math.max(l, max), r);
        if (isLeftChild) {
            return r + 1;
        }
        return l + 1;
    }

}