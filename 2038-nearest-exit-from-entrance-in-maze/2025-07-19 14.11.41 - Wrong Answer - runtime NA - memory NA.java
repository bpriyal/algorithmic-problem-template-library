class Solution {
        int l;
        int r;
        int top;
        int bottom;
    int count = 0;
    public int nearestExit(char[][] maze, int[] entrance) {
         l = 0;
         r = maze[0].length - 1;
         top = 0;
         bottom = maze[0].length - 1;
        List<List<Integer>> es = new ArrayList();
        for (int i = 0; i < maze.length; ++i) {
            for (int j = 0; j < maze[0].length; ++j) {
                if (i == entrance[0] && j == entrance[1]) continue;
                if (((i == top || i == bottom) || (j == l || j == r)) && maze[i][j] == '.' ) {
                    es.add(Arrays.asList(i, j));
                }
            }
        }
        int minSteps = Integer.MAX_VALUE;
        boolean possible = false;
        for (List<Integer> block : es) {
            count = 0;
            int val = dfs(block.get(0), block.get(1), entrance, maze, 0, new boolean[maze.length][maze[0].length]);
            // if minSteps = Math.min(count, minSteps);
            minSteps = Math.min(val, minSteps);
        }
        minSteps = minSteps == Integer.MAX_VALUE ? -1 : minSteps;
        return minSteps;
    }

    int dfs (int i, int j, int[] e, char[][] maze, int c, boolean[][] visited) {
        if (i < 0 | i >= maze.length | j < 0 | j >= maze[0].length) return Integer.MAX_VALUE;
        if (visited[i][j]) return Integer.MAX_VALUE;
        if (i == e[0] && j == e[1]) {count = c; return c;}
        if (maze[i][j] == '+') return Integer.MAX_VALUE;
        visited[i][j] = true;
        int rval = dfs(i, j + 1, e, maze, c + 1, visited);
        int lval = dfs(i, j - 1, e, maze, c + 1, visited);
        int bottom = dfs(i + 1, j, e, maze, c + 1, visited);
        int top = dfs(i - 1, j, e, maze, c + 1, visited);
        return minval(rval, lval, bottom, top);
    }

    int minval (int a, int b, int c, int d) {
        return Math.min(a, Math.min(b, Math.min(c, d)));
    }
}