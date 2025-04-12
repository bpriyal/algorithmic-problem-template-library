class Solution {
    int rows, cols;
    inline static vector<pair<int, int>> offsets = { {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

    int countAdjacentMines(const vector<vector<char>>& board, int row, int col) {
      auto counter = [&](int newRow, int newCol) -> int {
        if (newRow < 0 || newRow == rows || newCol < 0 || newCol == cols) return 0;
        if (board[newRow][newCol] == 'M') return 1;
        return 0;
      };
      int mines = 0;
      for (const auto& offset : offsets) {
        mines += counter(row + offset.first, col + offset.second);
      }
      return mines;
    }

    void dfs(vector<vector<char>>& board, int row, int col) {
      if (row < 0 || row == rows || col < 0 || col == cols) return;

      if (board[row][col] == 'M') {
        board[row][col] = 'X';
        return;
      }

      if (board[row][col] == 'E') {
        auto adjacentMines = countAdjacentMines(board, row, col);
        if (adjacentMines) board[row][col] = ('0' + adjacentMines);
        else {
          board[row][col] = 'B';

          for (const auto& offset : offsets) {
            dfs(board, row + offset.first, col + offset.second);
          }
        }
      }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
      rows = board.size();
      cols = board[0].size();

      dfs(board, click[0], click[1]);
      
      return board;
    }
};