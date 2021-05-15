/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* slow = nullptr;
        ListNode* fast = head;
        
        while(fast) {
            ListNode* temp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = temp;
        }
        
        return slow;
    }
};