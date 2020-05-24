class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        if (A.size() ==0 || B.size() == 0) return result;
        int i=0,j=0;
        while(i<A.size() && j<B.size()) {
            vector<int> a = A[i];
            vector<int> b = B[j];
            
            if (b[1] < a[0]) ++j;
            else if (a[1] < b[0]) ++i;
            else {
                int r_f = (a[0] > b[0]) ? a[0]: b[0];
                int r_l = (a[1] > b[1]) ? b[1] : a[1];
                result.push_back({r_f,r_l});
                if (r_l == a[1]) ++i;
                else ++j;
            }
        }
        return result;
    }
};