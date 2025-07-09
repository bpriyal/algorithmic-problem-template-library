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
        if (head.next == null) return null;
        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = head;
        while (fast.next != null) {
            prev = slow;
            slow = slow.next;
            if (fast.next.next != null) {     
                fast = fast.next.next;
            } else {
                break;
            }
        }
        prev.next = slow.next;
        slow = null;
        return head;
    }
}