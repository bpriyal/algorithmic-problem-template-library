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
    public int pathSum(TreeNode root, int targetSum) {
        helper(root, targetSum, new ArrayDeque<Integer>(), 0);
        return count;
    }
    void helper (TreeNode root, int target, ArrayDeque<Integer> q, int sum) {
        if (root == null) return;
        q.add(root.val);
        sum += root.val;
        if (sum == target) count++;
        int s = sum;
        Queue<Integer> copy = new ArrayDeque<Integer>(q);
        while (!copy.isEmpty()) {
            s -= copy.poll();
            if (s == target) {
                count++;
            }
        }
        helper(root.left, target, q, sum);
        // q.pollLast();
        helper(root.right, target, q, sum);
        // q.pollLast();
    }
}