/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int k = lists.length;
        if (lists == null || k == 0) return null;
        Queue<ListNode> heads = new PriorityQueue<ListNode>(new Comparator<ListNode>() {
       @Override
        public int compare(ListNode a, ListNode b) {
            // System.out.println(a.val+" "+b.val);
            return a.val-b.val;
        }
    });
        ListNode resultHead = new ListNode();
        for (ListNode top : lists) {
            if (top == null) continue;
            heads.offer(top);
        }

        if(heads.isEmpty()) return null;

        ListNode temp = heads.poll();
        resultHead = new ListNode(temp.val);  
        ListNode curr = resultHead;
        if (temp.next != null) heads.offer(temp.next);
        
        while (!heads.isEmpty()) {
            temp = heads.poll();
            if (temp.next != null) heads.offer(temp.next);
            curr.next = new ListNode(temp.val);          
            curr = curr.next;
        }

        return resultHead;

    }
}