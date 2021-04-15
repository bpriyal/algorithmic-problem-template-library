class Solution {
public:
    int fib(int n) {
        /*vector<int> cache;
        cache.push_back(0);
        cache.push_back(1);*/
        
        if (n == 0 || n == 1) {
            return n;
        }
        int sl = 0;
        int l = 1;
        int curr;
        
        for(int i = 2;i <= n;++i) {
            curr = sl + l;
            sl = l;
            l = curr;
        }
        
        return curr;
    }
};