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
        if(head.next == null){
            return head;
        }
    
        ListNode even = new ListNode(head.next.val);
        ListNode first = even;
        ListNode newEven;

        odd.next = odd.next.next;
        odd = odd.next; 
        
        while(odd.next != null){    //atleast next even val exists

            //put next val as even to a new list
            newEven = new ListNode(odd.next.val, null);
            even.next = newEven;
            even = even.next;

            //next odd val exists
            //total odd no of nodes
            if(odd.next.next != null){            
                odd.next = odd.next.next;
                odd = odd.next;       
            }

            //next odd val does not exist
            //total even no of nodes
            else{ 
                //odd.next is NOT null 
                //odd.next.next IS null
                odd.next = null;    
            }
        }

        odd.next = first;
        return head;
    }
}