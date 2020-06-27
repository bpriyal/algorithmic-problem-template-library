class Solution {
    int count = INT_MAX;
    vector<int> cache;
    void util(int n,int run) {
        if (run >= count) return;
        if (n == 0) {
            count = min(count,run);
            return;
        }
        if (n < 0) return;
        for (int i =0;i<cache.size();++i) {
            if (cache[i] > n) break;
            util(n-cache[i],run+1);
        }
    }
public:
    int numSquares(int n) {
        if (n ==0) return 0;
        for(int i =1;i<=sqrt(n);++i) {
            cache.push_back(i*i);
        }
        util(n,0);
        return count;
    }
};