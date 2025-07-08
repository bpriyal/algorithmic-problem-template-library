class Solution {
    public int equalPairs(int[][] grid) {
        Map<Integer, Integer> rows = new HashMap();
        int count = 0;
        for (int[] row : grid) {
            int r = hashRow(row);
            rows.put(r, rows.getOrDefault(r, 0) + 1);
        }
        for (int i = 0; i < grid.length; ++i) {
            int[] col = new int[grid.length];
            for (int j = 0; j < grid[i].length; ++j) {
                col[j] = grid[j][i];
            }
            int c = hashRow(col);
            if (rows.containsKey(c)) count += rows.get(c);
        }
        return count;
    }

    int hashRow(int[] row) {
        int num = 0;
        for (int i : row) {
            num += num*1000 + i;
        }
        return num;
    }
}