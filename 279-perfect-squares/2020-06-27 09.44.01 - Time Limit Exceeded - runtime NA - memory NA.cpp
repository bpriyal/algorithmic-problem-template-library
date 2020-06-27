class Solution {
    int count = INT_MAX;
    void util(int n,int run) {
        if (n == 0) {
            count = min(count,run);
            return;
        }
        if (n < 0) return;
        vector<int> cache;
        for(int i =1;i<=sqrt(n);++i) {
            cache.push_back(i*i);
        }
        for (int i =0;i<cache.size();++i) {
            util(n-cache[i],run+1);
        }
    }
public:
    int numSquares(int n) {
        util(n,0);
        return count;
    }
};