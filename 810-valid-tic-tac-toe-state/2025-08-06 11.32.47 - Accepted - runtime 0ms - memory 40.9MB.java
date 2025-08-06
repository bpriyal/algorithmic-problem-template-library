class Solution {
    public boolean validTicTacToe(String[] board) {
        int[] row1 = new int[3];
        int[] row2 = new int[3];
        int[] col1 = new int[3];
        int[] col2 = new int[3];
        int dia1 = 0;
        int dia2 = 0;
        int adia1 = 0;
        int adia2 = 0;
        int x = 0;
        int o = 0;
        boolean xtrue = false;
        boolean otrue = false;

        int i = 0;
        for (String r : board) {
            int j = 0;
            for (char c : r.toCharArray()) {
                // if (c == ' ') continue;
                if (c == 'X') {
                    row1[i]++;
                    col1[j]++;
                    if (i == j) dia1++;
                    if (i + j == 2) adia1++;
                    x++;
                    if (row1[i] == 3 || col1[j] == 3 || dia1 == 3 || adia1 == 3) xtrue = true;
                } else if (c == 'O') {
                    row2[i]++;
                    col2[j]++;
                    if (i == j) dia2++;
                    if (i + j == 2) adia2++;
                    o++;
                    if (row2[i] == 3 || col2[j] == 3 || dia2 == 3 || adia2 == 3) otrue = true;
                }
                j++;
            }
            i++;
        }

        if (o > x) return false;
        if (x - o > 1) return false;
        if (x - o != 1) if (xtrue) return false;
        if (x - o != 0) if (otrue) return false;
        return true;
    }
}

// X O X
// O X O
// _ O X

// X O X
// X _ O
// X _ O