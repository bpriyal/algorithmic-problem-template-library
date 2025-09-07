class Solution {
    public void setZeroes(int[][] matrix) {
        boolean[] rows = new boolean[matrix.length];
        boolean[] cols = new boolean[matrix[0].length];
        for (int i = 0; i < matrix.length; ++i) {
            for (int j = 0; j < matrix[0].length; ++j) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (int ind = 0; ind < matrix.length; ++ind) {
            if (rows[ind]) {
                for (int jind = 0; jind < matrix[0].length; ++jind) {
                    matrix[ind][jind] = 0;
                }
            } else {
                for (int jind = 0; jind < matrix[0].length; ++jind) {
                    if (cols[jind]) matrix[ind][jind] = 0;
                }
            }
        }

    }
}