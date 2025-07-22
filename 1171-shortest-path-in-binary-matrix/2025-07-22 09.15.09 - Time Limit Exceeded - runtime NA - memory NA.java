class Solution {
    int MAX = Integer.MAX_VALUE;
    int MIN = Integer.MAX_VALUE;
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) grid[i][j] = MAX;
            }
        }
        boolean visited[][] = new boolean[n][m];
        dfs (grid, n - 1, m - 1, visited, 1);
        MIN = MIN == MAX ? -1 : MIN;
        return MIN;
    }

    void dfs (int[][] grid, int i, int j, boolean[][] visited, int count) {
        int n = grid.length;
        int m = grid[0].length;
        if (i < 0 || i >= n || j < 0 || j >= m) return;
        if (grid[i][j] == MAX) return;
        if (i == 0 && j == 0) {
            MIN = Math.min(MIN, count);
            return;
        }
        if (visited[i][j]) return;
        int[][] copy = grid;
        //  new int[n][m];
        // copy = Arrays.stream(grid).map(int[]::clone).toArray(int[][]::new);
        visited[i][j] = true;
        boolean[][] cv = new boolean[n][m];
        cv = Arrays.stream(visited).map(boolean[]::clone).toArray(boolean[][]::new);
        
        // copy[i][j] = Math.min(copy[i][j], count);
        dfs (copy, i - 1, j - 1, visited, count + 1);
        visited = cv;
        dfs (copy, i, j - 1, visited, count + 1);
        visited = cv;
        dfs (copy, i + 1, j - 1, visited, count + 1);
        visited = cv;
        dfs (copy, i + 1, j, visited, count + 1);
        visited = cv;
        dfs (copy, i + 1, j + 1, visited, count + 1);
        visited = cv;
        dfs (copy, i, j + 1, visited, count + 1);
        visited = cv;
        dfs (copy, i - 1, j + 1, visited, count + 1);
        visited = cv;
        dfs (copy, i - 1, j, visited, count + 1);
        visited = cv;
        // visited[i][j] = false;

    }
}