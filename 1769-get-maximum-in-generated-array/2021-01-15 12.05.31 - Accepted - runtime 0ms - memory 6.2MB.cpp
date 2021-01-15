class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        int result = 1;
        vector<int> cache(n+1,0);
        cache[0] = 0;
        cache[1] = 1;
        for(int i = 1;i<=n/2;++i) {
            if (2*i <= n) {
                cache[2*i] = cache[i];
                result = max(result,cache[2*i]);
            } else {
                break;
            }
            
            if (2*i+1 <= n) {
                cache[2*i+1] = cache[i] + cache[i+1];
                result = max(result,cache[2*i+1]);  
            } else {
                break;
            } 
        }
        
        return result;
    }
};