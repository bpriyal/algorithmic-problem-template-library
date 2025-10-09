class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int r = -1;
        int i = 0;
        int n = matrix.length;
        for (i = 0; i < n; ++i) {
            if (target < matrix[i][0]) {
                r = i - 1;
                break;
            }
        }
        if (r == -1) {
            if (i == 0) return false;
            r = n - 1;
        }
        int m = matrix[0].length;
        if (target > matrix[r][m - 1]) return false;
        for (int j = 0; j < m; ++j) {
            if (target == matrix[r][j]) 
                return true;
        } 
        return false; 
    }
}