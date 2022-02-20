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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size = 0;
        while (temp) {
            ++size;
            temp = temp->next;
        }
        
        if (size == 1) {
            return nullptr;
        }
        cout<<size<<endl;
        temp = head;
        for(int i = 0;i < size-n-1;++i) {
            temp = temp->next;
        }
        ListNode* nodeToDelete = temp->next;
        //cout<<nodeToDelete->val;
        temp->next = nodeToDelete->next;
        delete(nodeToDelete);
        
        return head;
    }
};