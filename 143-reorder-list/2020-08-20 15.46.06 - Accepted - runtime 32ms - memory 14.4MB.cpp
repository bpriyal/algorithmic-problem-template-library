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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }
        
        ListNode* slowptr=head;
        ListNode* fastptr=head->next;
        
        while(fastptr != nullptr && fastptr->next != nullptr){
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;   
        }
        
        fastptr=slowptr->next;
        slowptr->next=nullptr;
        
        ListNode* c=fastptr;
        ListNode* p=nullptr;
        ListNode* n=nullptr;
        
        while(c != nullptr){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }

        ListNode* q=head->next;

        ListNode* st=head;
        
        while(p && q){
            st->next=p;
            st=st->next;
            p=p->next;
            st->next=q;
            st=st->next;
            q=q->next;
        }
        if(q){
            st->next=q;
        }
         if(p){
             st->next=p;
         }
    }
};