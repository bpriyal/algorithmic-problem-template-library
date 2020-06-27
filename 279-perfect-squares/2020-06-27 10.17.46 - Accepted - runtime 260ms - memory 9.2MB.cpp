class Solution {
    vector<int> cache;
    vector<int> dp;
    int util(int n) {
        if (n == 0) {
            return 0;
        }
        if (n < 0) return 1001;
        if (dp[n] == -1) {
            int min_ = INT_MAX;
            for (int i =0;i<cache.size();++i) {
                if (cache[i] > n) break;
                min_ = min(min_,1+util(n-cache[i]));
            }
            dp[n] = min_;
        }          
        return dp[n];
    }
public:
    int numSquares(int n) {
        /*if (n ==0) return 0;
        for(int i =1;i<=sqrt(n);++i) {
            cache.push_back(i*i);
        }
        dp.resize(n+1,-1);
        util(n);
        return dp[n]; */
        
        //solution 2
        vector<int> cache(n+1,0);
        for(int x = 1;x <= n;++x) {
            int min_ = x;
            int y = 1, square = 1;
            while(square <= x) {
                min_ = min(min_, 1 + cache[x-square]);
                ++y;
                square = y*y;
            }
            cache[x] = min_;
        }
        return cache[n];
    }
};