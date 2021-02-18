class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size();
        int temp = 0,result = 0;
        for(int i = 2;i < size;++i) {
            if (A[i]-A[i-1] == A[i-1]-A[i-2]) {
                temp = 1+temp;
                result += temp;
            } else {
                temp = 0;
            }
        }
        return result;
    }
};