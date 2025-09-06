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
        if (n == 0) return head;
        ListNode first = head;
        ListNode second = head;
        ListNode prev = null;
        int rem = n;

        while (rem > 0 && second != null) {
            second = second.next;
            rem--;
        }
        if (second == first) return null;
        while(second != null) {
            prev = first;
            first = first.next;
            second = second.next;
        }
        if (prev == null) return head.next;
        prev.next = first.next;
        first = null;

        return head;
    }
}