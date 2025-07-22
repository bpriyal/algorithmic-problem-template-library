class Solution {

    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        if (n == 0 || m == 0 || grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;
        grid = mark(grid);
        int res = dfs(grid, grid.length - 1, grid[0].length - 1, 0);
        res = res < Integer.MAX_VALUE ? res : -1;
        return res;
    }

    int[][] mark (int grid[][]) {
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[0].length; ++j) {
                if (grid[i][j] == 1) grid[i][j] = -1;
            }
        }
        return grid;
    }

    int dfs (int[][] grid, int i, int j, int count) {
        int n = grid.length;
        int m = grid[0].length;
        if (i < 0 || i >= n || j < 0 || j >= m) return Integer.MAX_VALUE;
        if (grid[i][j] == -1) return Integer.MAX_VALUE;
        if (i == 0 && j == 0) return 1;
        if (grid[i][j] > 0) return grid[i][j];
        int[][] copy = new int[n][m];
        copy = Arrays.stream(grid).map(int[]::clone).toArray(int[][]::new);
        copy[i][j] = count;
        int a = dfs (copy, i, j + 1, count + 1);
        int b = dfs (copy, i + 1, j + 1, count + 1);
        int c = dfs (copy, i - 1, j + 1, count + 1);
        int d = dfs (copy, i, j - 1, count + 1);
        int e = dfs (copy, i + 1, j - 1, count + 1);
        int f = dfs (copy, i - 1, j - 1, count + 1);
        int g = dfs (copy, i - 1, j, count + 1);
        int h = dfs (copy, i + 1, j, count + 1);
        ArrayList<Integer> res = new ArrayList(Arrays.asList(a, b, c, d, e, f, g, h));
        grid[i][j] = Collections.min(res);
        return Collections.min(res) + 1;
    }

    // int min (int a, int b, c, d, e, f, g, h)
}