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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* oldEven = head->next;
        
        while (even && odd) {
            
            if (even->next) {
                odd->next = even->next;
                odd = odd->next;
            } else break;
            
            if (odd->next) {
                even->next = odd->next;
                even = even->next;
            } else break;
        }
        even->next = nullptr;
        odd->next = oldEven;
        ListNode* temp = head;
        cout<<head->val<<endl;
        while(temp) {
            cout<<temp->val<<endl;
            temp = temp->next;
        }
        return head;
    }
};