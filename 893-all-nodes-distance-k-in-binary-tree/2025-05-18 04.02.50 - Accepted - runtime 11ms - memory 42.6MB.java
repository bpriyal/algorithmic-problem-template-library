/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {

    List<Integer> VALS;
    Set<TreeNode> visited;
    Map<TreeNode, TreeNode> nodeToParent = new HashMap<>();

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        VALS = new LinkedList();
        visited = new HashSet();
        nodeToParent.put(root,null);
        setParents(root);
        helper(target, k);
        return VALS;
    }

    void setParents(TreeNode root) {
        if (root == null) return;
        if (root.left != null) nodeToParent.put(root.left, root);
        if (root.right != null) nodeToParent.put(root.right, root);
        setParents(root.left);
        setParents(root.right);
    }

    void helper (TreeNode root, int remainingLevels) {
        if (root == null) return;
        if (visited.contains(root)) return;
        if (remainingLevels == 0) {
            VALS.add(root.val);
            return;
        }
        visited.add(root);
        remainingLevels--;
        helper(root.left, remainingLevels);
        helper(root.right, remainingLevels);
        helper(nodeToParent.get(root), remainingLevels);
    }

}