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
        /*ListNode* ptr1 = head,*ptr2 = head;
        
        if (n == 1) {
            if (ptr1->next == nullptr) {
                return nullptr;
            }
            
            while(ptr1->next->next != nullptr) {
                ptr1 = ptr1->next;
            }
            
            ptr1->next = nullptr;
            return head;
        }
        
        int counter = 0;
        
        while(ptr1->next != nullptr) {
            ptr1 = ptr1->next;
            ++counter;
            if (counter%n==0) {
                cout<<"kkk"<<endl;
                ptr2 = ptr2->next;
                counter = 0;
            }
        }
        cout<<"he;;"<<endl;
        ptr2->next = ptr1;
        
        return head;*/
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) fast = fast->next;
        if (!fast) return head->next;
        while (fast->next) fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }
};