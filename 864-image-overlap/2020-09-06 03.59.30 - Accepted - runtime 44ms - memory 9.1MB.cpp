class Solution {
    int util(vector<vector<int>>& A, vector<vector<int>>& B,int yunit,int xunit) {
        int rf=0,count=0;
        int size = A.size();
        for(int i = yunit;i<size;++i) {
            int cf = 0;
            for(int j = xunit;j<size;++j) {
                if (A[i][j] == 1 && B[rf][cf] == 1) {
                    ++count;
                }
                ++cf;
            }
            ++rf;
        }
        return count;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int size = A.size();
        int maxOverlap = INT_MIN;
        for(int i=0;i<size;++i) {
            for(int j = 0;j<size;++j) {
                maxOverlap = max({maxOverlap,util(A,B,i,j),util(B,A,i,j)});
            }
        }
        return maxOverlap;
    }
};