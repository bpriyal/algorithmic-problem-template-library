class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> cache;
        int rows = wall.size();
        
        for(int i =0;i < rows;++i) {
            int temp = 0;
            for(int j = 0;j < wall[i].size() - 1;++j) {
                ++cache[temp+wall[i][j]];
                temp += wall[i][j];
            } 
        }
        
        
        int result = INT_MIN;
        for(auto it = cache.begin();it != cache.end();++it) {
            //cout<<it->first<<","<<it->second<<endl;
            result = max(result,it->second);
        }
        
        return result == INT_MIN? rows:rows-result;
    }
};