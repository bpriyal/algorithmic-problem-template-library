class Solution {

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adjList = new ArrayList();
        for (int i = 0; i < numCourses; ++i) {
            adjList.add(new ArrayList());
        }
        for (int set[] : prerequisites) {
            adjList.get(set[0]).add(set[1]);
        }
        for (int i = 0; i < numCourses; ++i) {
            Set<Integer> temp = new HashSet();
            if (!check (adjList, i, temp))
                // || temp.contains(i)) 
                    return false;
        }
        return true;
    }

    boolean check (List<List<Integer>> adjList, int course, Set<Integer> line) {
        if (line.contains(course)) return false;
        line.add(course);
        List<Integer> direct = adjList.get(course);
        for (int connected : direct) {
            if (!check (adjList, connected, line)) 
                return false;
            line.remove(connected);
        }
        return true;
    }
}

// 0 1 2 3 4

// 0 1 
// 2 0
// 1 3


// 2 0 1 3 
