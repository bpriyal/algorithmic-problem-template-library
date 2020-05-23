class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        if (A.size() ==0 || B.size() == 0) return result;
        int i=0,j=0;
        while(i<A.size() && j<B.size()) {
            int a_f = A[i][0];
            int a_l = A[i][1];
            int b_f = B[j][0];
            int b_l = B[j][1];
            
            if (b_l < a_f) ++j;
            else if (a_l < b_f) ++i;
            else {
                int r_f = (a_f > b_f) ? a_f: b_f;
                int r_l = (a_l > b_l) ? b_l : a_l;
                result.push_back({r_f,r_l});
                if (r_l == a_l) ++i;
                else ++j;
            }
        }
        return result;
    }
};