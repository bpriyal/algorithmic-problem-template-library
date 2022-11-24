class Solution {
    int rows, cols;
    vector<vector<bool>> visited;
    int util(const vector<vector<char>>& maze, const vector<int>& entrance, int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || maze[row][col] == '+' ||  visited[row][col]) return INT_MAX;
        if ((row == 0 || row == rows - 1 || col == 0 || col == cols - 1) && vector<int>{row, col} != entrance) return 0;
        visited[row][col] = true;

        int result = min({
            util(maze, entrance, row + 1, col),
            util(maze, entrance, row - 1, col),
            util(maze, entrance, row, col + 1),
            util(maze, entrance, row, col - 1)
        });

        visited[row][col] = false;

        return result == INT_MAX? -1 : result + 1;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        rows = maze.size();
        cols = maze[0].size();

        visited.resize(rows, vector<bool>(cols, false));

        return util(maze, entrance, entrance[0], entrance[1]);
    }
};