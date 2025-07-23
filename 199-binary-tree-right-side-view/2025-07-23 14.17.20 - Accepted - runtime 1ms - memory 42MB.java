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
 class TreeNode {
      int val;
        int level;
     TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
         this.val = val;
          this.left = left;
         this.right = right;
      }
  }
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) return new ArrayList();
        // if (root)
        Queue<TreeNode> q = new LinkedList();
        root.level = 1;
        int level = 2;
        q.offer(root);
        List<Integer> res = new ArrayList<Integer>();
        res.add(root.val);
        // q.offer(null);
        do {
            // if (q.peek() != null)
            TreeNode curr = q.poll();
            int currLevel = curr.level;
            if (curr.right != null) {
                curr.right.level = currLevel + 1;
                if (level == currLevel + 1) {
                    level++;
                    res.add(curr.right.val);
                }
                q.offer(curr.right);
            }
            if (curr.left != null) {
                curr.left.level = currLevel + 1;
                if (level == currLevel + 1) {
                    level++;
                    res.add(curr.left.val);
                } 
                q.offer(curr.left);
            }
            // q.offer(null);
            // q.offer(curr);
        } while (!q.isEmpty());

        // TreeNode node = root;
        // while (node != null)
        //     System.out.println(n.val + " " + n.level);
        // }

        // // int lev = 1;
        // List<Integer> res = new ArrayList<Integer>();
        // while (!q.isEmpty()) {
        //     if(q.peek().level > 0)
        //         res.add(q.poll().val);
        // }
        // // System.out.println(q);
        return res;
    }
}