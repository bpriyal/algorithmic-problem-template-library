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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = l1;
        ListNode prev = l1;
        // ListNode prev = l1;
        int rem = 0;
        while (l1 != null || l2 != null) {
            if (l1 == null && rem != 0) {l1 = new ListNode(rem); rem = rem/10; prev.next = l1;}
            else if (l2 == null && rem != 0) {l2 = new ListNode(rem); rem = rem/10;}
            rem = addGiveRem(l1, l2, rem);
            prev = l1;
            l1 = l1.next;
            l2 = l2.next; 
        }
        if (rem != 0) {
            prev.next = new ListNode(rem);
        }
        return head;
    }

    int addGiveRem(ListNode l1, ListNode l2, int rem) {
        int n = l1.val + l2.val + rem;
        l1.val = n % 10;
        return (n / 10);
    }
}