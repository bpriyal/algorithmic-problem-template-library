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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> retList = new LinkedList();
        int delim = 111;
        if (root == null) return new LinkedList();
        Queue<TreeNode> q = new LinkedList();  
        q.add(new TreeNode(delim)); 
        q.add(root);

        while (!q.isEmpty()) {   
            TreeNode curr = q.poll();
            if (curr.val == delim) {
                curr = q.poll();
                if (curr == null) break;
                retList.add(curr.val);
                q.add(new TreeNode(delim));
            }
            if (curr.right != null) q.add(curr.right);
            if (curr.left != null) q.add(curr.left);
        }

        return retList;
    }
}