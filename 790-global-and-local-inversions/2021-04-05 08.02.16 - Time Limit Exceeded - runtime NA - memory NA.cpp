class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int size = A.size();
        for(int i = 0;i < size - 1;++i) {
            for(int j = i+2;j < size;++j) {
                if (A[j] < A[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};