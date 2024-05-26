class TicTacToe {
    vector<vector<int>> _board;
    int _size;

    int checkStatus() {
        int row, col;
        // Check row wise winner
        for (row = 0; row < _size; ++row) {
            bool allEqual = true;
            for (col = 1; col < _size; ++col) {
                if (_board[row][col] == 0 || _board[row][col - 1] != _board[row][col]) {
                    allEqual = false;
                    break;
                }
            }
            if (allEqual) return _board[row][col - 1];
        }
        // check column wise
        for (col = 0; col < _size; ++col) {
            bool allEqual = true;
            for (row = 1; row < _size; ++row) {
                if (_board[row][col] == 0 || _board[row - 1][col] != _board[row][col]) {
                    allEqual = false;
                    break;
                }
            }
            if (allEqual) return _board[row - 1][col];
        }
        // check Diagonals
        for (int rowCol = 1; rowCol < _size; ++rowCol) {
            if (_board[rowCol][rowCol] == 0) break;
            if (_board[rowCol - 1][rowCol - 1] != _board[rowCol][rowCol]) break;
            if (rowCol == _size - 1) return _board[rowCol][rowCol];
        }
        for (int revRowCol = 1; revRowCol < _size; ++revRowCol) {
            if (_board[revRowCol][_size - revRowCol - 1] == 0) break;
            if (_board[revRowCol][_size - revRowCol - 1] != _board[revRowCol - 1][_size - revRowCol - 1 + 1]) break;
            if (revRowCol == _size - 1) return _board[revRowCol][_size - revRowCol - 1];
        }
        return 0;
    }

public:
    TicTacToe(int n) {
        _board.resize(n, vector<int>(n, 0));
        _size = n;
    }
    
    int move(int row, int col, int player) {
        _board[row][col] = player;
        return checkStatus();
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */