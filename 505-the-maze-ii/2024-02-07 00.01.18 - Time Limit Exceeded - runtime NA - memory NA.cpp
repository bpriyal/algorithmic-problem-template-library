class Solution {
    int _rows, _cols;
    void dfs(vector<vector<int>>& maze, const vector<int>& current, vector<int>& destination, vector<vector<int>>& distance) {
        vector<int> X = {-1, 1, 0, 0 };
        vector<int> Y = {0, 0, -1, 1};        
        for (int i = 0; i < 4; ++i) {
            int distanceTraversed = 0;
            int row = current[0] + Y[i], col = current[1] + X[i];
            while (row >= 0 && row < _rows && col >= 0 && col < _cols && maze[row][col] == 0) { // O(m + n)
                row += Y[i];
                col += X[i];
                ++distanceTraversed;
            }
            if (distance[current[0]][current[1]] + distanceTraversed < distance[row - Y[i]][col - X[i]]) {
                distance[row - Y[i]][col - X[i]] = distance[current[0]][current[1]] + distanceTraversed;
                dfs(maze, {row - Y[i], col - X[i]}, destination, distance);
            }
            // if (auto dist = dfs(maze, {row - Y[i], col - X[i]}, destination, visited); dist != -1) {
            //     cout<<dist<<endl;
            //     minDistanceTraversed = min(minDistanceTraversed, distanceTraversed + dist);
            // }
        }
    }
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        _rows = maze.size();
        _cols = maze[0].size();
        vector<vector<int>> distance(_rows, vector<int>(_cols, INT_MAX));
        distance[start[0]][start[1]] = 0;
        dfs(maze, start, destination, distance);
        return distance[destination[0]][destination[1]] == INT_MAX? -1 : distance[destination[0]][destination[1]];
    }
};