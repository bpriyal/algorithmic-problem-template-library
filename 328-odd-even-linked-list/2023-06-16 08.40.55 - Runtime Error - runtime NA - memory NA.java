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
        // ListNode even = head.next;
        ListNode odd = head;
        if(head == null){
            return null;
        }
        
        ListNode last = head;
        while(last.next != null){
            last = last.next;
        }
    
        ListNode even = new ListNode(head.next.val);
        ListNode first = even;
        
        odd.next = odd.next.next;
        odd = odd.next; 
        
        while(odd.next != null && odd.next.next != null){
            ListNode newEven = new ListNode(odd.next.val, null);
            even.next = newEven;
            even = even.next;
            odd.next = odd.next.next;
            odd = odd.next;         
        }
        last.next = first;
        return head;
    }
}