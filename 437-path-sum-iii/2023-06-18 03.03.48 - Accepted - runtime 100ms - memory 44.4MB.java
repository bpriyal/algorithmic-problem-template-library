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
    static private int TARGET;
    public int pathSum(TreeNode root, int targetSum) {
        Solution.TARGET = targetSum;
        return paths(root,new ArrayList<>());
        //{{add(root.val);}}
    }

    int paths(TreeNode node, List<Long> sums){
        int count = 0;

        if(node != null){
            sums.add(0L);
            for(int i = 0 ; i < sums.size(); ++i){
                sums.set(i, sums.get(i) + node.val);        
                if(sums.get(i) == TARGET){
                    ++count;
                }
            }
            count += paths(node.left, sums) + paths(node.right,sums);
            for(int i = 0 ; i < sums.size(); ++i){
                sums.set(i, sums.get(i) - node.val);        
            }
            sums.remove(sums.size()-1);
        }

        return count;
    }
}