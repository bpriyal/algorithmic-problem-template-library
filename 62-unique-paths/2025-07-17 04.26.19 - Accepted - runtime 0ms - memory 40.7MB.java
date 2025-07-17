class Solution {
    public int uniquePaths(int m, int n) {
        int[][] grid = new int[m][n];
        return botWalk(grid, m - 1, n - 1);
    }

    int botWalk(int[][] grid, int i, int j) {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        if (grid[i][j] != 0) return grid[i][j];

        int left = botWalk(grid, i - 1, j);
        int up = botWalk(grid, i, j - 1);

        grid[i][j] = left + up;
        return grid[i][j];
    }
}
