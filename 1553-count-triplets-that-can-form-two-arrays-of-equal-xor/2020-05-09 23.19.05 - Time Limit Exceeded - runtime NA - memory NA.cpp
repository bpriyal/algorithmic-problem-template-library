class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int i,j,k;
        int size = arr.size();
        int count=0;
        for (i=0;i<size-1;++i) {
            for (j = i+1;j<size;++j) {
                for (k = j;k<size;++k) {
                    int a = 0,b = 0;
                    int temp = i;
                    while (temp <= j-1) {
                        a = a ^ arr[temp];
                        ++temp;
                    }
                    temp = j;
                    while (temp <= k) {
                        b = b ^ arr[temp];
                        ++temp;
                    }
                    if (a == b) ++count;                   
                }
            }
        }
        return count;
    }
};