class TicTacToe {
    vector<vector<int>> _board;
    int _size;

    int checkStatus() {
        // Check row wise winner
        for (int row = 0; row < _size; ++row) {
            for (int col = 1; col < _size; ++col) {
                cout<<"row: "<<row<<", col: "<<col<<endl;
                if (_board[row][col - 1] != _board[row][col]) break;
                if (col == _size - 1) return _board[row][col];
            }
        }
        // check column wise
        for (int col = 0; col < _size; ++col) {
            for (int row = 1; row < _size; ++row) {
                cout<<"col: "<<col<<", row: "<<row<<endl;
                if (_board[row - 1][col] != _board[row][col]) break;
                if (row == _size - 1) return _board[row][col];
            }
        }
        // check Diagonals
        for (int rowCol = 1; rowCol < _size; ++rowCol) {
            cout<<"rowCol: "<<rowCol<<endl;
            if (_board[rowCol - 1][rowCol - 1] != _board[rowCol][rowCol]) break;
            if (rowCol == _size - 1) return _board[rowCol][rowCol];
        }
        for (int revRowCol = 1; revRowCol < _size - 1; ++revRowCol) {
            cout<<"revRowCol: "<<revRowCol<<endl;
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