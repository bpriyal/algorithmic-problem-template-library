class Solution {
public:
    double myPow(double x, int n) {
        /* times out
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
        */
        //cout<<n<<endl;
        bool isNegative = (n < 0)? true:false;
        n = abs(n);
        if (n == 1) return x;
        double res;
        if (n%2 != 0) {
            --n;
            res = myPow(x,n/2);
            if (isNegative) {
                return (1.0/(res*res*x));
            } else {
                return res*res*x;
            }
        } else {
            res = myPow(x,n/2);
            if (isNegative) {
                return (1.0/(res*res));
            } else {
                return res*res;
            }
        }
    }
};