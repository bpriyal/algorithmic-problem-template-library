class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {

        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int,int>> q;             // carry out BFS
        vector<vector<int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}};   // 4 types of moves

        vector<vector<int>> dp(m, vector<int> (n,INT_MAX)); //since question is to find min, initialize max

        q.push(make_pair(start[0],start[1]));
        dp[start[0]][start[1]] = 0;         // dist from start = 0
        
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;
            for(auto& v: direction)         // we check for all the 4 directions in this loop
            {
                int nr = r + v[0];
                int nc = c + v[1];
                int count =0;              // dist covered in current roll

                while(nr >= 0 && nr<m &&  nc >=0 && nc < n && maze[nr][nc] ==0)
                {
                    nr += v[0];
                    nc += v[1];
                    count ++;
                }
                // Come back to last non-wall place where the ball will stop
                nr -= v[0];
                nc -= v[1];

                // update distance of this path if its shorter than any existing prev path
                if (dp[r][c] + count < dp[nr][nc]) {
                    dp[nr][nc] = dp[r][c] + count;
                    q.push({nr, nc});
                }
            }
        }
        
        // we just have to return dp od destination for min distance
        return dp[destination[0]][destination[1]] == INT_MAX? -1: dp[destination[0]][destination[1]];

    }
};