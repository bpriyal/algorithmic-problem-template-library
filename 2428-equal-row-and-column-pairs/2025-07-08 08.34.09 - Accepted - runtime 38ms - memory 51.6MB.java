class Solution {
    public int equalPairs(int[][] grid) {
        Map<String, Integer> rows = new HashMap();
        int count = 0;
        for (int[] row : grid) {
            StringBuilder sb = new StringBuilder();
            for (int i : row) {
                sb.append(i);
                sb.append(" ");
            }
            rows.put(sb.toString(), rows.getOrDefault(sb.toString(), 0) + 1);
        }
        for (int i = 0; i < grid.length; ++i) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < grid[i].length; ++j) {
                sb.append(grid[j][i]);
                sb.append(" ");
            }
            if (rows.containsKey(sb.toString())) count += rows.get(sb.toString());
        }
        return count;
    }
}