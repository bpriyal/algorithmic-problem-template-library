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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode prev = null;
        ListNode first = head;
        ListNode second = head;
        int i = 1;
        while (i++ < n) second = second.next;
        while (second.next != null) {
            prev = first;
            first = first.next;
            second = second.next;
        }
        if (prev == null) return null;
        prev.next = first.next;
        first = null;
        return head;
    }
}