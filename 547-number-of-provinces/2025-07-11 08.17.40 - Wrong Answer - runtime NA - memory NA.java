class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        Map<Integer, Integer> cityToGroup = new HashMap();
        boolean[] visited = new boolean[n];
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    if (cityToGroup.containsKey(j)) {
                        cityToGroup.put(i, cityToGroup.get(j));
                        visited[i] = true;
                    }
                }
            }
            if (!cityToGroup.containsKey(i)) {
                cityToGroup.put(i, ++count);
            }
        }
        return count;
    }
}