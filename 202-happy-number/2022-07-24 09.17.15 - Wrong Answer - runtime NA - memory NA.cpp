class Solution {
public:
    bool isHappy(int n) {
        while(true) {
            if (n < 10) return n == 1;
            
            int sum = 0;
            while(n) {
                sum += (n%10) * (n%10);
                n /= 10;
            }
            
            
            if (sum == n) return false;
            
            n = sum;
        }
        
        return false;
    }
};