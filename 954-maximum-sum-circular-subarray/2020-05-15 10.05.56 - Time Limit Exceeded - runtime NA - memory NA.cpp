class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int size = A.size();
        int i,j,x,y;
        int sum,max = A[0];
        for (i = 1;i<=size;++i) {
            sum = 0;
            for (j = 0;j<i;++j) {
                sum += A[j];
                if (sum > max) max = sum;
            }
            if (i == size) {
                if (sum > max) {
                    max = sum;
                }
                return max;
            }
            for (x=0,y=i;x<size-1;++x,++y) {
                if (y>=size) y -= size;
                sum += A[y] - A[x];
                //cout<<sum<<endl;
                if (sum > max) max = sum;
            }
        }
        return -1;
    }
};