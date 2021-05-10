class Solution {
public:
    int countPrimes(int n) {
        vector<bool> cache(n,true);
        int count = 0;
        
        for(int i = 2;i*i < n;++i) {
            if (!cache[i]) {
                continue;
            }
            
            for(int j = i*i;j < n;j += i) {
                cache[j] = false;
            }
        }
        
        for(int i = 2;i < n;++i) {
            count += cache[i] ? 1:0;
        }
        
        return count;
    }
};