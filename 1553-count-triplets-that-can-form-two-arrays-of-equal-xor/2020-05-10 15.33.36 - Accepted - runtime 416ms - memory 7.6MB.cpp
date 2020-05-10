class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int i,j,k;
        int size = arr.size();
        int count=0;
        vector<int> prev(size+1);
        prev[0] = 0;
        for (i= 1;i<=size;++i) {
            prev[i] = prev[i-1] ^ arr[i-1];
        }
        for (i=0;i<size-1;++i) {
            for (j = i+1;j<size;++j) {
                for (k = j;k<size;++k) {
                    int a = 0,b = 0;
                    a = prev[i] ^ prev[j];
                    b = prev[j] ^ prev[k+1];
                    if (a == b) ++count;                  
                }
            }
        }
        return count;
    }
};