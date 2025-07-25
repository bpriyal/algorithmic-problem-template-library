class Solution {
    
    Map<Integer, List<Integer>> adj = new HashMap();
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> copy = adj;
        int n = numCourses;       
        int cn = 0;
        for (int[] pair : prerequisites) {
            adj.computeIfAbsent(pair[0], x -> new ArrayList()).add(pair[1]);
        }
        for (int i = 0; i < n; ++i) {
            boolean[] visited = new boolean[n];
            if (!dfs(i, visited)) return false;
        }
        return true;      
    }

    boolean dfs (int course, boolean[] visited) {
        Map<Integer, List<Integer>> map = adj;
        if (visited[course]) return false;
        visited[course] = true;
        List<Integer> preList = adj.get(course);
        if (preList == null || preList.size() == 0) return true;
        for (int i : preList) {
            if (!visited[i] && i < course) return true;
            boolean[] copy = Arrays.copyOf(visited, visited.length);
            if (!dfs(i, copy)) return false;
        }
        return true;
    }
}