class Solution {
    int _rows, _cols, _currentOriginRow, _currentOriginCol;
    std::set<set<pair<int, int>>> _uniqueIslands;
    // vector<vector<vector<int>>> _uniqueIslands;
    void util(vector<vector<int>>& grid, int row, int col, std::set<pair<int, int>>& coordinates_) {
        if (row < 0 || row >= _rows || col < 0 || col >= _cols) return;
        if (grid[row][col] == 0 || grid[row][col] == -1) return;
        coordinates_.emplace(std::make_pair(row - _currentOriginRow, col - _currentOriginCol));
        grid[row][col] = -1;
        util(grid, row - 1, col, coordinates_);
        util(grid, row + 1, col, coordinates_);
        util(grid, row, col - 1, coordinates_);
        util(grid, row, col + 1, coordinates_);
    }
    // void subtractRootCoordinate(vector<vector<int>>& coordinates_) {
    //     if (coordinates_.empty()) return;
    //     for (int i = 1; i < coordinates_.size(); ++i) {
    //         coordinates_[i][0] -= coordinates_[0][0];
    //         coordinates_[i][1] -= coordinates_[0][1];
    //     }
    //     coordinates_[0][0] = 0;
    //     coordinates_[0][1] = 0;
    // }
    // bool isUniqueIsland(vector<vector<int>>& coordinates_) {
    //     int size = coordinates_.size();
    //     if (coordinates_.empty()) return false;
    //     if (_uniqueIslands.empty()) return true;
    //     for (const auto& island : _uniqueIslands) {
    //         if (island == coordinates_) return false;
    //     }
    //     return true;
    // }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        _rows = grid.size();
        _cols = grid[0].size();
        for (int row = 0; row < _rows; ++row) {
            for (int col = 0; col < _cols; ++col) {
                if (grid[row][col] == 1) {
                    _currentOriginRow = row;
                    _currentOriginCol = col;
                    std::set<pair<int, int>> coordinates;
                    util(grid, row, col, coordinates);
                    _uniqueIslands.emplace(coordinates);
                }
            }
        }
        return _uniqueIslands.size();
    }
};