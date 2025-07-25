class Solution {
    // boolean visited
    int ID = -1;
    int MIN = Integer.MIN_VALUE;
    int MAX = Integer.MIN_VALUE;
    Map<List<Integer>, Integer> islandToSize = new HashMap();
    public int largestIsland(int[][] grid) {
        int n = grid.length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int start = ID;
                    dfs(grid, i, j);
                    int end = ID;
                    int size = start - end;
                    MAX = Math.max(MAX, size);
                    islandToSize.put(Arrays.asList(start, end), size);
                }
            }
        }
        Map<List<Integer>, Integer> copy = islandToSize;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    closestTo0 (grid, i, j, 0, copy);
                    int max = MAX;
                }
            }
        }
        
        System.out.println(grid);
        int max = MAX;
        return MAX;
    }

    void dfs (int[][] grid, int i, int j) {
        int n = grid.length;  
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return;
        }
        if (grid[i][j] <= 0) return;
        if (grid[i][j] == 1) grid[i][j] = ID--;
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

    int closestTo0(int[][] grid, int i, int j, int dist, Map<List<Integer>, Integer> copy) {
        // Map<List<Integer>, Integer> copy = new HashMap(islandToSize);
        if (dist > 1) return -1;
        if (i < 0 || i >= grid.length || j < 0 || j >= grid.length) return 0;
        if (grid[i][j] != 0 && dist == 1) {
            int thisSize = findSize(grid[i][j], copy);
            return thisSize;
        }
        List<Integer> islands = new ArrayList();
        if (grid[i][j] == 0 && dist < 1) {
            islands.add(closestTo0(grid, i - 1, j, dist + 1, copy));
            islands.add(closestTo0(grid, i + 1, j, dist + 1, copy));
            islands.add(closestTo0(grid, i, j - 1, dist + 1, copy));
            islands.add(closestTo0(grid, i, j + 1, dist + 1, copy));
            Collections.sort(islands, Collections.reverseOrder());
            if (islands.get(0) != -1 && islands.get(1) != -1) {
                int big = islands.get(0) + islands.get(1) + 1;
                MAX = Math.max(MAX, big);
                return big;
            }
            return -1;
        }
        return -1;
        
    }

    int findSize(int ID, Map<List<Integer>, Integer> map) {
        for (List<Integer> pair : map.keySet()) {
            if (ID <= pair.get(0) && ID > pair.get(1)) {
                int size = islandToSize.get((pair));
                map.remove(pair);
                return size;
            }
        }
        return -1;
    }
}