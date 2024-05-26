class TicTacToe {
    vector<int> rows, cols;
    int diagonal, antiDiagonal;
    int _size;
public:
    TicTacToe(int n) {
        rows.resize(n, 0);
        cols.resize(n, 0);
        diagonal = antiDiagonal = 0;
        _size = n;
    }
    
    int move(int row, int col, int player) {
        int incrDecr = player == 1? 1 : -1;
        rows[row] = rows[row] + incrDecr;
        cols[col] = cols[col] + incrDecr;
        if (row == col) diagonal = diagonal + incrDecr;
        if (col == _size - 1 - row) antiDiagonal = antiDiagonal + incrDecr;

        if (rows[row] == _size || cols[col] == _size || diagonal == _size || antiDiagonal == _size) return 1;
        else if (rows[row] == -1 * _size || cols[col] == -1 * _size || diagonal == -1 * _size || antiDiagonal == -1 * _size) return 2;
        else return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */