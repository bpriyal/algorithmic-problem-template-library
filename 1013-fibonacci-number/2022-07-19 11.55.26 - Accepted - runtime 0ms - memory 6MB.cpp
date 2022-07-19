class Solution {
    vector<int> cache;
    
    int util(int n) {
        if (n == 0 || n == 1) return n;
        cache[n] = util(n-1) + util(n-2);
        
        return cache[n];
    }
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        
        int a = 0;
        int b = 1;
        
        for(int i = 2;i <= n;++i) {
            int temp = a + b;
            a = b;
            b = temp;
        }
        
        return b;
    }
};