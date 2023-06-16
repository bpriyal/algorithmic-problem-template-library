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
    public ListNode deleteMiddle(ListNode head) {

        if(head == null || head.next == null){
            return null;
        }
        ListNode slow = head;
        ListNode fast = head;
        ListNode savePrev = head;

        while(fast.next != null){
            if(fast.next.next != null){
                fast = fast.next.next;
            }
            else{
                fast = fast.next;
            }
            savePrev = slow;
            slow = slow.next;          
        }
        savePrev.next = savePrev.next.next;
        slow = null;
        return head;
    }
}