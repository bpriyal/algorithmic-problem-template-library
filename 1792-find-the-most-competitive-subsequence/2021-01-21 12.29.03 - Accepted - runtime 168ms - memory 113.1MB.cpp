class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int size = nums.size();
        int numbersToDelete = size - k;
        vector<int> st;
        for(int num:nums) {
            while (!st.empty() && numbersToDelete > 0 && num < st.back()) {
                st.pop_back();
                --numbersToDelete;
            }
            st.push_back(num);
        }
        return vector<int>(st.begin(),st.begin()+k);
    }
};