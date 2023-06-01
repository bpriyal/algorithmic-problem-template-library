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
        int num1 = getNumber(l1);
        int num2 = getNumber(l2);

        return makeNodes(num1 + num2);
    }

    int getNumber(ListNode ln){
        ListNode node = ln;
        int num = 0;
        for(int i = 0; node != null; node = node.next, ++i){
            num += node.val * Math.pow(10,i);
        }
        return num;
    }

    ListNode makeNodes(int num){
        if(num == 0){
            return new ListNode(0);
        }
        ListNode head = new ListNode();
        ListNode node = head;
        for(int i = 0; num > 0; ++i){
        //    node = new ListNode();
            node.next = new ListNode();
            node = node.next;
            node.val = num % 10;
            num /= 10;    
        }
        return head.next;
    }
}