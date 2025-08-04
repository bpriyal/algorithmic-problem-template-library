class Solution {

    public boolean canFinish(int n, int[][] prerequisites) {
        List<List<Integer>> adjList = new ArrayList();
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; ++i) {
            adjList.add(new ArrayList());
        }
        for (int set[] : prerequisites) {
            adjList.get(set[0]).add(set[1]);
        }
        for (int i = 0; i < n; ++i) {
            Set<Integer> temp = new HashSet();
            if (!check (adjList, i, temp, dp))
                // || temp.contains(i)) 
                    return false;
        }
        return true;
    }

    boolean check (List<List<Integer>> adjList, int course, Set<Integer> line, int[][] dp) {
        if (line.contains(course)) return false;
        line.add(course);
        List<Integer> direct = adjList.get(course);
        for (int connected : direct) {
            if (dp[course][connected] != 0) {
                if (dp[course][connected] == -1) return false;
                return true;
            }
            if (!check (adjList, connected, line, dp)) {
                dp[course][connected] = -1;
                return false;
            }
            dp[course][connected] = 1;        
            line.remove(connected);
        }
        return true;
    }
}
