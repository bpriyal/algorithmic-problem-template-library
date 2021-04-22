class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> cache;
        int rows = wall.size();
        
        for(int i =0;i < rows;++i) {
            int temp = 0;
            for(int j = 0;j < wall[i].size() - 1;++j) {
                ++cache[temp+wall[i][j]];
                temp = wall[i][j];
            } 
        }
        
        
        int result = 0;
        int temp = INT_MIN;
        for(auto it = cache.begin();it != cache.end();++it) {
            if (it->second > temp) {
                temp = it->second;
                result = it->first;
            }
        }
        
        return rows-result;
    }
};