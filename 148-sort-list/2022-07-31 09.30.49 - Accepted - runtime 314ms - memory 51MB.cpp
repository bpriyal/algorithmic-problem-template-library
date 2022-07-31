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
    int getSize(ListNode* node) {
        int size = 0;
        ListNode* temp = node;
        
        while(temp) {
            ++size;
            temp = temp->next;
        }
        
        return size;
    }
    
    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        //Decide head
        if (list1->val < list2->val) { 
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        
        ListNode* temp = head;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }
        
        temp->next = list1? list1 : list2;
        
        return head;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head ||!head->next) return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* temp = slow->next;
        slow->next = nullptr;
        // cout<<"here"<<endl;
        
        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(temp);
        return mergeLists(list1, list2);
    }
};