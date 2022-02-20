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
        
        //cout<<size<<endl;
        temp = head;
        
        for(int i = 0;i < size-n-1;++i) {
            temp = temp->next;
        }
        
        if (temp == head && size == n) {
            head = temp->next;
            delete(temp);
        } else {
            ListNode* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete(nodeToDelete);
        }
        
        return head;
    }
};