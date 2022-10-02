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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        unordered_map<int, queue<int>> map;
        ListNode* temp = head;
        vector<int> result;
        
        while (temp) {
            while (!st.empty() && st.top() < temp->val) {
                map[st.top()].push(temp->val);
                st.pop();
            }
            
            st.push(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        
        while (temp) {
            if (map.find(temp->val) != map.end()) {
                result.push_back(map[temp->val].front());
                map[temp->val].pop();
            } else result.push_back(0);
            temp = temp->next;
        }
        
        return result;
    }
};