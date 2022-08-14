class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cache;
    
        while(true) {
            int sum = 0;
            cache.insert(n);
            
            while(n) {
                sum += (n%10) * (n%10);
                n /= 10;
            }
            
            n = sum;
            
            if (sum == 1) return true;
            if (cache.find(sum) != cache.end()) return false;
        }
        
        return false;
    }
};