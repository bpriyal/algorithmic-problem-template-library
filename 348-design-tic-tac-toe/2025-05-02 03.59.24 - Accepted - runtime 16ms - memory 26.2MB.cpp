class TicTacToe {
    vector<int> rowMoves;
    vector<int> colMoves;
    int diagonalMoves = 0;
    int antiDiagonalMoves = 0;
    int _n;
public:
    TicTacToe(int n) {
      rowMoves.resize(n, 0);
      colMoves.resize(n, 0);
      _n = n;
    }
    
    int move(int row, int col, int player) {
      // update row and check if winner
      player == 1 ? rowMoves[row]++ : rowMoves[row]--;
      if (abs(rowMoves[row]) == _n) return player;

      // update col and check if winner
      player == 1 ? colMoves[col]++ : colMoves[col]--;
      if (abs(colMoves[col]) == _n) return player;

      // main diagonal
      if (row == col) {
        player == 1 ? ++diagonalMoves : --diagonalMoves;
        if (abs(diagonalMoves) == _n) return player;
      }

      // anti diagonal
      if (row + col == _n - 1) {
        player == 1 ? ++antiDiagonalMoves : --antiDiagonalMoves;
        if (abs(antiDiagonalMoves) == _n) return player;
      }

      return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */