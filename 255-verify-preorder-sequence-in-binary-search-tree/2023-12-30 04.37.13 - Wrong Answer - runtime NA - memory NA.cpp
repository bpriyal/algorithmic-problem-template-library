class Solution {
    int _size;
    void _verifyPreorder(vector<int>& preorder, int left, int right) {
        
    }
public:
    bool verifyPreorder(vector<int>& preorder) {
        _size = preorder.size();
        stack<int> st;
        st.emplace(preorder[0]);
        for (int i = 1; i < _size; ++i) {
            if (st.empty()) return false;
            if (st.top() > preorder[i]) {
                st.emplace(preorder[i]);
            } else {
                while (!st.empty() && preorder[i] > st.top()) {
                    // lastPopped = st.top();
                    st.pop();
                }
            }
        }
        return true;
    }
};