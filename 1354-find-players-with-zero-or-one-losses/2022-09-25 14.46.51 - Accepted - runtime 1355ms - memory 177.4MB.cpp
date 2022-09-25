class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> cache;
        
        for (auto it : matches) {
            ++cache[it[1]];
            
            if (cache.find(it[0]) == cache.end()) cache[it[0]] = 0;
        }
        
        vector<vector<int>> result(2);
        
        for (auto it = cache.begin(); it != cache.end(); ++it) {
            if (it->second == 0) result[0].push_back(it->first);
            else if (it->second == 1) result[1].push_back(it->first);
        }
        
        sort(result[0].begin(), result[0].end());
        sort(result[1].begin(), result[1].end());
        
        return result;
    }
};