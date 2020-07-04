class Solution {
public:
    int nthUglyNumber(int n) {
        /* TLE
        vector<int> cache;
        cache.push_back(1);
        int number = 2;
        while(cache.size() != n) {
            for(int i = cache.size() - 1;i >= 0;--i) {
                if (cache[i]*2 == number || cache[i]*3 == number || cache[i]*5 == number) {
                    //cout<<number<<endl;
                    cache.push_back(number);
                    break;
                }
            }
            ++number;
        }
        return cache[cache.size()-1];
        TLE */
        
        
        if (n == 1) return 1;
        vector<int> cache;
        cache.push_back(1);
        int n1 = 0,n2 = 0,n3 = 0,min_ = INT_MAX;
        for(int i = 1;i < n;++i) {
            min_ = min({cache[n1]*2,cache[n2]*3,cache[n3]*5});
            if (min_ == cache[n1]*2) {
                ++n1;
            }
            if (min_ == cache[n2]*3) {
                ++n2;
            }
            if (min_ == cache[n3]*5) {
                ++n3;
            }
            cache.push_back(min_);
        }
        return cache[n-1];
    }
};