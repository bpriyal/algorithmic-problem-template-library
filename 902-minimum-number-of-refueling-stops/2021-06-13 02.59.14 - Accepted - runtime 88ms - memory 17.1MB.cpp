class Solution {
    int util(int target,long fuel,unordered_map<int,int> &cache,int pos,int stops) {
        if (pos == 1000000) {
            
        
        cout<<pos<<endl;}
        if (pos == target) {
            return stops;
        }
        
        if (fuel < 0) {
            return INT_MAX;
        }
        
        --fuel;
        
        int result = INT_MAX;
        if (cache.find(pos) != cache.end()) {
            // take the fuel and stop
            result = util(target,fuel+cache[pos],cache,pos+1,stops+1);
            
            // don't take this stop
            
            result = min(result,util(target,fuel,cache,pos+1,stops));
        } else {
            result = util(target,fuel,cache,pos+1,stops);
        }
        
        return result;
    }
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        /*unordered_map<int,int> cache;
        
        for(vector<int> &station:stations) {
            cache[station[0]] = station[1];
        }
        
        int result = util(target,static_cast<long>(startFuel),cache,0,0);
        
        return result == INT_MAX? -1:result;*/
        
        vector<long> dp(501,startFuel);
        int size = stations.size();
        
        for(int i = 0;i < size;++i) {
            for(int t = i;t >= 0 && dp[t] >= stations[i][0];--t) {
                dp[t+1] = max(dp[t+1],dp[t]+stations[i][1]);
            }
        }
        for (int t = 0; t <= size; ++t)
            if (dp[t] >= target) return t;
        return -1;
    }
};