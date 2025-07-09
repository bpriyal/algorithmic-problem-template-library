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
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) return head;
        ListNode odd = head;
        ListNode even = head.next;
        ListNode fast = even.next;
        ListNode evenEnd = even;

        while (fast != null && fast.next != null) {
            // fast = even.next;
            // if (fast.next.next == null) break;
            // fast = fast.next.next;
            ListNode temp = fast.next;
            odd.next = fast;
            fast.next = even;
            evenEnd.next = temp;
            odd = odd.next;
            evenEnd = temp;
            fast = temp.next;
        }
        if (fast != null) {
            odd.next = fast;
            fast.next = even;
            evenEnd.next = null;
        }
        return head;
    }
}

// 1 2 3 4 5 6 7 8 9
// 1 3 2 4 5 6 7 8 9


