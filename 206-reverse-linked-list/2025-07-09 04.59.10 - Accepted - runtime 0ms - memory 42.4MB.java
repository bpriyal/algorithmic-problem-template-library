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
    public ListNode reverseList(ListNode head) {
        if (head == null) return null;
        if (head.next == null) return head;
        ListNode first = head;
        ListNode h = head;
        ListNode move = head.next;   
        while (move != null) {
            ListNode temp = move.next;
            h.next = temp;
            move.next = first;
            first = move;
            move = temp; 
        }
        return first;
    }
}

// 1 2 3 4 5

// 2 1 3 4 5
// m f t
// f   m
//       t
// 2 1 4 5
// 3 4

// 3 2 1 4 5
// m f h t
// f.  h m t

