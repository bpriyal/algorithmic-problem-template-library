class Solution {
    int util(int target,int fuel,unordered_map<int,int> &cache,int pos,int stops) {
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
        unordered_map<int,int> cache;
        
        for(vector<int> &station:stations) {
            cache[station[0]] = station[1];
        }
        
        int result = util(target,startFuel,cache,0,0);
        
        return result == INT_MAX? -1:result;
    }
};