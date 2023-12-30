class Solution {
    int _size;
    void _verifyPreorder(vector<int>& preorder, int left, int right) {
        
    }
public:
    bool verifyPreorder(vector<int>& preorder) {
        _size = preorder.size();
        stack<int> st;
        st.emplace(preorder[0]);
        int minLimit = 0;
        for (int i = 1; i < _size; ++i) {
            if (minLimit >= preorder[i]) return false;
            if (st.top() < preorder[i]) {
                while (!st.empty() && preorder[i] > st.top()) {
                    minLimit = st.top();
                    st.pop();
                }
            }
            st.emplace(preorder[i]);
        }
        return true;
    }
};