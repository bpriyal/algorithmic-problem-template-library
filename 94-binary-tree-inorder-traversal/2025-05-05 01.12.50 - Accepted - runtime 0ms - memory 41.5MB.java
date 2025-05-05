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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> output = new LinkedList<>();
        helper(root, output);
        return output;
    }
    
    public void helper (TreeNode node, List<Integer> outputBuilt) { //return type is void
        if (node == null)
            return; //
        helper(node.left, outputBuilt); //returns when leaf encounters and does nothing here as return type is void, when return type is void, reaching null you just return to parent that is a leaf, and helper(node.left, outputBuilt) will do nothing but execute and skip to next line of code, now it means left children have gotten over
        //now you can store the value
        outputBuilt.add(node.val);
        helper(node.right, outputBuilt);
    }
}