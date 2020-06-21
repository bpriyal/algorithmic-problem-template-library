class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        vector<vector<int>> cache(rows,vector<int>(cols,0));
        for(int i = rows-1;i>=0;--i) {
            for(int j = cols-1;j>=0;--j) {
                if (i == rows-1 && j ==cols-1) {
                    cache[i][j] = min(0,dungeon[i][j]);
                }
                else if (j == cols-1) {
                    cache[i][j] = min(0,dungeon[i][j]+cache[i+1][j]);
                } else if (i == rows-1) {
                    cache[i][j] = min(0,dungeon[i][j]+cache[i][j+1]);
                } else {
                    cache[i][j] = min(0,dungeon[i][j]+max(cache[i+1][j],cache[i][j+1]));
                }
            }
        }
        return -cache[0][0] + 1;
    }
};
