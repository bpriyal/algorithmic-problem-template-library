class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        Queue<Integer> q = new LinkedList();
        boolean[] visited = new boolean[rooms.size()];
        q.add(0);
        visited[0] = true;
        int count = 1;
        while (!q.isEmpty()) {
            int ind = q.poll();
            for (int key : rooms.get(ind)) {
                if (!visited[key]) {
                    q.add(key);
                    count++;
                    visited[key] = true;
                }  
            }
        }
        return (count == rooms.size());
    }
}