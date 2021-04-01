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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        int size = 0;
        ListNode *temp = head;
        
        while(temp != nullptr) {
            ++size;
            temp = temp->next;
        }
        
        int i = 0;
        ListNode *curr = nullptr;
        ListNode *ahead = head;
        ListNode* ahead2 = nullptr;
        
        while (i < size/2) {
            ahead2 = ahead->next;
            ahead->next = curr;
            curr = ahead;
            ahead = ahead2;
            ++i;
        }
        
        if (size%2 == 0) {
        } else {
            ahead = ahead->next;
        }
        
        while(curr && ahead) {
            if (curr->val != ahead->val) {
                return false;
            }
            curr = curr->next;
            ahead = ahead->next;
        }
        
        if (!curr && !ahead) {
            return true;
        }
        return false;
    }
};