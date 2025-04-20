class Solution {
    vector<vector<int>> adjMap;
    vector<int> visited;
    bool dfs(int i) {
      if (visited[i] == 2) return true;
      visited[i] = 1; // in recursion
      for (int course : adjMap[i]) {
        if (visited[course] == 1) return false; // in current stack, there is a cycle
        if (!dfs(course)) return false;
      }
      visited[i] = 2;
      return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      adjMap.resize(numCourses);
      visited.resize(numCourses, 0);
      for (const auto& prereq : prerequisites) {
        adjMap[prereq[1]].emplace_back(prereq[0]);
      }
      for (int i = 0; i < numCourses; ++i) {
        if (!visited[i]) {
          if (!dfs(i)) return false;
        }
      }
      return true;
    }
};

// 0 -> 1
// 1 -> 0

// [1, 2] [0, 1]

// 0
// 1 -> 0
// 2 -> 1