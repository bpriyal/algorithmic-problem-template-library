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
    int count = 0;

    public int averageOfSubtree(TreeNode root) {
        isAvgCount (root);
        return count;
    }

    int[] isAvgCount(TreeNode root) {
        if (root == null) return new int[2];
        int[] l = isAvgCount(root.left);
        int[] r = isAvgCount(root.right);
        int sum = l[0] + r[0] + root.val;
        int n = l[1] + r[1] + 1;
        if (sum/n == root.val) count++;
        int[] ret = {sum, n};
        return ret;
    }
}