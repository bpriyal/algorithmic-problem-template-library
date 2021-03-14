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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int size = 0;
        
        while(temp != nullptr) {
            temp = temp->next;
            ++size;
        }
        
        ListNode *backTemp = head;
        temp = head;
        
        for(int i = 0;i < k-1;++i) {
            temp = temp->next;
        }
        
        for(int i = 0;i < size-k;++i) {
            backTemp = backTemp->next;
        }
        
        int t = temp->val;
        temp->val = backTemp->val;
        backTemp->val = t;
        
        return head;
    }
};