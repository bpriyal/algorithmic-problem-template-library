class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1) return 1;
        double result = 1.0;
        if (n < 0) {
            for(int i =0;i<-n;++i) {
                result /= x;
                //cout<<result<<endl;
            }
        } else {
            for(int i =0;i<n;++i) {
                result *= x;
                //cout<<result<<endl;
            }
        }
        return result;
    }
};