class Solution {
    unordered_map<int, vector<int>> adjList;
    bool util(int course, vector<bool>& visited) {
      if (visited[course]) return false;
      visited[course] = true;
      
      auto it = adjList.find(course);
      if (it == adjList.end()) return true;
      for (const auto& depCourse : it->second) {
        if (!util(depCourse, visited)) return false;
      }
      return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      for (const auto& dep : prerequisites) {
        adjList.try_emplace(dep[0], dep[1]);
      }

      for (int i = 0; i < numCourses; ++i) {
        vector<bool> visited(numCourses);
        if (!util(i, visited)) return false;
      }
      return true;
    }
};