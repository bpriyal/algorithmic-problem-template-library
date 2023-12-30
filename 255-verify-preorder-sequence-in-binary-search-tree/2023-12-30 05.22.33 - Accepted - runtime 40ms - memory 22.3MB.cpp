class Solution {
    int _size;
    void _verifyPreorder(vector<int>& preorder, int left, int right) {
        
    }
public:
    bool verifyPreorder(vector<int>& preorder) {
        // _size = preorder.size();
        // stack<int> st;
        // st.emplace(preorder[0]);
        // int minLimit = 0;
        // for (int i = 1; i < _size; ++i) {
        //     if (minLimit >= preorder[i]) return false;
        //     if (st.top() < preorder[i]) {
        //         while (!st.empty() && preorder[i] > st.top()) {
        //             minLimit = st.top();
        //             st.pop();
        //         }
        //     }
        //     st.emplace(preorder[i]);
        // }
        // return true;

        _size = preorder.size();
        int minLimit = 0, j = 1;
        for (int i = 1; i < _size; ++i) {
            if (minLimit >= preorder[i]) return false;
            if (preorder[j - 1] < preorder[i]) {
                while (j != 0 && preorder[i] > preorder[j-1]) {
                    minLimit = preorder[j - 1];
                    --j;
                }
            }
            preorder[j] = preorder[i];
            ++j;
        }
        return true;
    }
};