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
    Map<Integer, List<Integer>> colsToList = new TreeMap();
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        dfs (root, 0);
        List<List<Integer>> ret = new ArrayList(colsToList.values());
        for (List<Integer> inner : ret) {
            Collections.sort(inner);
        }
        return ret;
    }

    void dfs (TreeNode root, int col) {
        if (root == null) return;
        colsToList.computeIfAbsent(col, x -> new ArrayList<Integer>()).add(root.val);
        dfs (root.left, col - 1);
        dfs (root.right, col + 1);
        return;
    }
}