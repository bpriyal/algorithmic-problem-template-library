class TicTacToe {

    int[] row1;
    int[] col1;
    int[] row2;
    int[] col2;
    int dia1;
    int adia1;
    int dia2;
    int adia2;
    int totalMoves = 0;
    int n = 0;
    public TicTacToe(int N) {
            n = N;
            row1 = new int[n];
            row2 = new int[n];
            col1 = new int[n];
            col2 = new int[n];
            dia1 = 0;
            dia2 = 0;
            adia1 = 0;
            adia2 = 0;
            totalMoves = n * n;
    }
    
    public int move(int row, int col, int player) {
    int[] row1c = row1;
    int[] col1c = col1;
    int[] row2c = row2;
    int[] col2c = col2;
    int dia1c = dia1;
    int adia1c = adia1;
    int dia2c = dia2;
    int adia2c = adia2;
    int totalMovesc = totalMoves;
    int nc = n;
        if(--totalMoves == 0) return 0;
        if (player == 1) {
            row1[row]++;
            col1[col]++;
            if (row == col) dia1++;
            if (row + col == n - 1) adia1++;
            if (row1[row] == n || col1[col] == n || dia1 == n || adia1 == n) return 1;
        } else {
            row2[row]++;
            col2[col]++;
            if (row == col) dia2++;
            if (row + col == n - 1) adia2++;
            if (row2[row] == n || col2[col] == n || dia2 == n || adia2 == n) return 2;
        }
        return 0;
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */

// 00 01 02 03 04 05
// 10 11 12 13 14 15
// 20 21 22 23 24 25
// 30 31 32 33 34 35
// 40 41 42 43 44 45
// 50 51 52 53 54 55