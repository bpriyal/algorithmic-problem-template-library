class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int size = A.size();
        for(int i = 0;i < size;++i) {
            for(int j = 0;j <= size/2;++j) {
                int temp = A[i][size-j-1];
                A[i][size-j-1] = A[i][j] ? 0:1;
                A[i][j] = temp? 0:1;
            }
        }
        return A;
    }
};