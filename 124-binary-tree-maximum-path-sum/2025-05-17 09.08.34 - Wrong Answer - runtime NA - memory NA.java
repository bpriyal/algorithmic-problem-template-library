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
    public int maxPathSum(TreeNode root) {
        helper(root);
        return MAX;
    }

    int helper (TreeNode root) {
        if (root == null) return 0; 

        int l = helper(root.left);
        int r = helper(root.right);

        MAX = Math.max(MAX, max(l + root.val, r + root.val, l + root.val + r, root.val));

        return Math.max(l, r) + root.val;
    }

    int max (int n, int m, int p, int q) {
        return Math.max(q, Math.max(n, Math.max(m,p)));
    }
}