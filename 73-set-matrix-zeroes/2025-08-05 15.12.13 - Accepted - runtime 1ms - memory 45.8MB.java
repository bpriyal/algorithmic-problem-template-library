class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        boolean[] is = new boolean[m];
        boolean[] js = new boolean[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    is[i] = true;
                    js[j] = true;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            int j = 0;
            if (is[i]) while (j < n) matrix[i][j++] = 0;
        }
        for (int j = 0; j < n; ++j) {
            int i = 0;
            if (js[j]) while (i < m) matrix[i++][j] = 0;
        }

    }
}