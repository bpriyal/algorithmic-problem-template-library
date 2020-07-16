class Solution {
public:
    double myPow(double x, int n) {
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