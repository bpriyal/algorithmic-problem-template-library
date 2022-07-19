class Solution {
    vector<int> cache;
    
    int util(int n) {
        if (n == 0 || n == 1) return n;
        cache[n] = util(n-1) + util(n-2);
        
        return cache[n];
    }
public:
    int fib(int n) {
        cache.resize(n + 1, -1);
        
        return util(n);
    }
};