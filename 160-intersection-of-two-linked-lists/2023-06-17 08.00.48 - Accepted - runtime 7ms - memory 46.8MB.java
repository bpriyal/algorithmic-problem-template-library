/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null){
            return null;
        }
        Map<ListNode,Integer> nodeToFreq = new HashMap<>();
        ListNode l = headA;
        nodeToFreq.put(l,1);
        l = l.next;
        while(l != null){
            nodeToFreq.put(l,1);
            l = l.next;
        }

        l = headB;
        ListNode possible = null;
        while( l != null ){
            if(nodeToFreq.containsKey(l)){
                possible = l;
                break;
            }
            l = l.next;
        }
        return possible;
    }
}