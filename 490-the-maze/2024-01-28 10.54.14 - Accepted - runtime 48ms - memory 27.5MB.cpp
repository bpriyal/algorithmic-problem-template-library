class Solution {
    int _rows, _cols;
    bool dfs(vector<vector<int>>& maze, const vector<int>& current, vector<int>& destination, vector<vector<bool>>& visited) {
        if (visited[current[0]][current[1]]) return false;
        if (current == destination) return true;
        visited[current[0]][current[1]] = true;
        vector<int> X = {-1, 1, 0, 0 };
        vector<int> Y = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int row = current[0], col = current[1];
            while (row >= 0 && row < _rows && col >= 0 && col < _cols && maze[row][col] == 0) {
                row += Y[i];
                col += X[i];
            }
            if (dfs(maze, {row - Y[i], col - X[i]}, destination, visited)) return true;
        }
        return false;
    }
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        _rows = maze.size();
        _cols = maze[0].size();
        vector<vector<bool>> visited(_rows, vector<bool>(_cols, false));
        return dfs(maze, start, destination, visited);
    }
};