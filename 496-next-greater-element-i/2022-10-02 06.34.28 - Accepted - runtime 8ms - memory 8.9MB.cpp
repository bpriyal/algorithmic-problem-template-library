class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        stack<int> st;
        vector<int> result;
        
        for (int i = 0; i < nums2.size(); ++i) {
            while (!st.empty() && nums2[i] > st.top()) {
                map[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        for (int num : nums1) {
            result.push_back(map.find(num) != map.end()? map[num] : -1);
        }
        
        return result;
    }
};