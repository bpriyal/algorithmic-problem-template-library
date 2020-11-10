class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int size = A.size();
        int limit = size/2;
        if (size%2 != 0) {
            ++limit;
        }
        for(int i = 0;i < size;++i) {
            for(int j = 0;j < limit;++j) {
                int temp = A[i][size-j-1];
                A[i][size-j-1] = A[i][j] ? 0:1;
                A[i][j] = temp? 0:1;
            }
        }
        return A;
    }
};