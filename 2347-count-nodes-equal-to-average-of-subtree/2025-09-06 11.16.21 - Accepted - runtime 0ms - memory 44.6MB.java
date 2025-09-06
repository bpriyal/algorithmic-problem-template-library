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
    int COUNT = 0;
    public int averageOfSubtree(TreeNode root) {
        countAvgNodes (root);
        return COUNT;
    }

    int[] countAvgNodes(TreeNode node) {
        if (node == null) {
            return new int[]{0, 0};
        }
        int[] left = countAvgNodes (node.left);
        int[] right = countAvgNodes (node.right);
        int n = (left[1] + right[1] + 1);
        int total = (left[0] + right[0] + node.val);
        if (total / n == node.val) COUNT++;
        return new int[]{total, n};
    }
}