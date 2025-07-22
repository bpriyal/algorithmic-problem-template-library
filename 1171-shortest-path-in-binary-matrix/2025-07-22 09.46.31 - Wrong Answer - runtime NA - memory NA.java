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
        grid[n - 1][m - 1] = 1;
        dfs (grid, n - 1, m - 1, visited, 1);
        MIN = MIN == MAX ? -1 : MIN;
        return MIN;
    }

    void dfs (int[][] copy, int i, int j, boolean[][] visited, int count) {
        int n = copy.length;
        int m = copy[0].length;
        if (i < 0 || i >= n || j < 0 || j >= m) return;
        if (copy[i][j] == MAX) return;
        if (i == 0 && j == 0) {
            MIN = Math.min(MIN, count);
            return;
        }
        // if (visited[i][j]) return;
        // int[][] copy = grid;
        //  new int[n][m];
        // copy = Arrays.stream(grid).map(int[]::clone).toArray(int[][]::new);
        // visited[i][j] = true;
        // boolean[][] cv = new boolean[n][m];
        // cv = Arrays.stream(visited).map(boolean[]::clone).toArray(boolean[][]::new);
        if (copy[i][j] != 0 && count > copy[i][j]) return;
        copy[i][j] = count;
        // copy[i][j] = Math.min(copy[i][j], count);
        dfs (copy, i - 1, j - 1, visited, count + 1);
        // visited = cv;
        dfs (copy, i, j - 1, visited, count + 1);
        // visited = cv;
        dfs (copy, i + 1, j - 1, visited, count + 1);
        // visited = cv;
        dfs (copy, i + 1, j, visited, count + 1);
        // visited = cv;
        dfs (copy, i + 1, j + 1, visited, count + 1);
        // visited = cv;
        dfs (copy, i, j + 1, visited, count + 1);
        // visited = cv;
        dfs (copy, i - 1, j + 1, visited, count + 1);
        // visited = cv;
        dfs (copy, i - 1, j, visited, count + 1);
        // visited = cv;
        // setVisited(visited, i, j, n, m);
        // visited[i][j] = false;

    }

    void setVisited(boolean[][] visited, int i, int j, int n, int m) {
        if (i + 1 < n) {
            if (j + 1 < m)
                visited[i + 1][j + 1] = true;
            visited[i + 1][j] = true;
            if (j - 1 >= 0)
                visited[i + 1][j - 1] = true;
        }
        if (i - 1 >= 0) {
            visited[i - 1][j] = true;
            if (j - 1 >= 0)
                visited[i - 1][j - 1] = true;
            if (j + 1 < m)
                visited[i - 1][j + 1] = true;
        }
        if (j - 1 >= 0)
            visited[i][j -1] = true;
        if (j + 1 < m)
            visited[i][j + 1] = true;
        visited[i][j] = true;
        visited[0][0] = false;
    }
}