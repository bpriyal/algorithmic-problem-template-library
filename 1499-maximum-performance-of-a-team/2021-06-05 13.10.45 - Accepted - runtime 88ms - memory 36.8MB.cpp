class Solution {
    constexpr int mod() {
        return pow(10,9) + 7;
    }
    int util(int n,vector<int>& speed, vector<int>& efficiency, int k,int run,int sum,int _min) {
        if (k == 0) {
            return sum*_min;
        }
        if (run >= n) {
            return 0;
        }
        
        // take current employee
        int result = util(n,speed,efficiency,k-1,run+1,sum+speed[run],min(_min,efficiency[run]));
        
        // don't take current employee
        result = max(result,util(n,speed,efficiency,k,run+1,sum,_min));
        
        return result;
    }
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        //return util(n,speed,efficiency,k,0,0,INT_MAX);
        
        vector<pair<int,int>> cache;
        
        for(int i = 0;i < n;++i) {
            cache.push_back({efficiency[i],speed[i]});
        }
        
        sort(rbegin(cache),rend(cache));
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long sum = 0, result = INT_MIN;
        
        for(auto &[e,s]:cache) {
            pq.emplace(s);
            sum += s;
            
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            result = max(result,sum*e);
        }
        
        return result%mod();
    }
};