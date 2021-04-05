class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int size = A.size();
        for(int i = 0;i < size;++i) {
            if (abs(A[i]-i) > 1) {
                return false;
            }
        }
        return true;
    }
};