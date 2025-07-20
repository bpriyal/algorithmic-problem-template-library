class Solution {
    List<List<Integer>> newRotInds;
    List<List<Integer>> copy;
    int remRots = 0;
    public int orangesRotting(int[][] grid) {
        int total = 0;
        int time = -1;
        newRotInds = new ArrayList();
        copy = new ArrayList(newRotInds);

        for (int i = 0; i < grid.length; ++i) 
                for (int j = 0; j < grid[0].length; ++j) {
                    if (grid[i][j] == 2) {
                        newRotInds.add(new ArrayList(Arrays.asList(i, j)));
                    } else if (grid[i][j] == 1) remRots++;
                }

        if (remRots == 0) return 0;
                    
//newRotInds != null && newRotInds.size() > 0
        while (remRots > 0) {
            for (List<Integer> pair : newRotInds) {
                rotAdj(pair.get(0), pair.get(1), grid);
                copy.remove(pair);
            }
            if (remRots == 0) return time + 2;
            if (copy.size() > 0) {
                time++;
            } else break;
            newRotInds = new ArrayList(copy);
        }  
        if (remRots > 0) return -1;
        return time + 1;
    }

    int rotAdj (int i , int j, int[][] grid) {
        int b = rot(i - 1, j, grid);
        int t = rot(i + 1, j, grid);
        int l = rot(i, j - 1, grid);
        int r = rot(i, j + 1, grid);
        return b + t + l + r;
    }

    int rot (int i, int j, int[][] grid) {
        int n = grid.length - 1;
        int m = grid[0].length - 1;
        if (i < 0 || i > n || j < 0 || j > m) return 0;
        if (grid[i][j] == 1) {
            grid[i][j] = 2;
            copy.add(Arrays.asList(i, j));
            remRots--;
            return 1;
        }
        return 0;
    }
}