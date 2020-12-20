/*class Solution {
    int row,col;
    vector<vector<vector<int>>> dp;
    pair<int,int> util(const vector<vector<int>>& grid,vector<vector<vector<int>>> &dp,int i,int j1,int j2,int run1,int run2) {
        cout<<i<<row<<endl;
        if (i >= row) {
            cout<<run1<<endl;
            return make_pair(run1,run2);
        }
        if (j1 < 0 || j1 >= col || j2 < 0 || j2 >=col) {
            //cout<<"poi"<<endl;
            return {-1,-1};
        }
        if (dp[i][j1][0] != -1) {
            //cout<<"here"<<endl;
            return {dp[i][j1][0],dp[i][j2][1]};
        }
        int _max = INT_MIN;
        for(int k = -1;k <= 1; ++k) {
            for(int l = -1;l <= 1;++l) {
                pair<int,int> temp = util(
                grid,dp,i+1,j1+k,j2+l,run1+grid[i][j1],run2+grid[i][j2]);
                //printf("first:%d||second:%d\n",temp.first,temp.second);
                if (temp.first+temp.second > _max) {
                    _max = temp.first+temp.second;
                    
                    dp[i][j1][0] = temp.first;
                    dp[i][j2][1] = temp.second;
                } 
            }
        }
        return {dp[i][j1][0],dp[i][j2][1]};
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        dp.resize(row+1,vector<vector<int>>(col+1,vector<int>(2,-1)));
        pair<int,int> result = util(grid,dp,0,0,col-1,0,0);
        return result.first+result.second;
    }
};*/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (grid[0].size());
        vector<vector<int>> prev_dp(n, vector<int>(n));
        for (int row = 0; row < m; row++) {
            vector<vector<int>> current_dp(n, vector<int>(n));
            for (int c1 = 0; c1 < min(n, row + 1); c1++) {
                for (int c2 = max(0, n - 1 - row); c2 < n; c2++) {
                    int prev_max = 0;
                    for (int offset1 = max(0, c1 - 1); offset1 <= min(n - 1, c1 + 1); offset1++) {
                        for (int offset2 = max(0, c2 - 1); offset2 <= min(n - 1, c2 + 1); offset2++) {
                                prev_max = max(prev_max, prev_dp[offset1][offset2]);
                        }
                    }
                    if (c1 == c2)
                        current_dp[c1][c2] = prev_max + grid[row][c1];
                    else
                        current_dp[c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
                }
            }
            prev_dp = current_dp;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, prev_dp[i][j]);    
            }
        }
        return res;
    }
};