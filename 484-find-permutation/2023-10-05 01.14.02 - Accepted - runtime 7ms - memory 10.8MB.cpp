class Solution {
public:
    vector<int> findPermutation(string s) {
        int size = s.size();
        vector<int> result;
        stack<int> st;
        int i;
        for (i = 0; i < size; ++i) {
            if (s[i] == 'D') st.emplace(i + 1);
            else {
                result.emplace_back(i + 1);
                while (!st.empty()) {
                    result.emplace_back(st.top());
                    st.pop();
                }
            }
        }
        result.emplace_back(i + 1);
        while (!st.empty()) {
            result.emplace_back(st.top());
            st.pop();
        }
        return result;
    }
};