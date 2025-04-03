class Solution {
    unordered_map<int, vector<int>> adjList;
    bool util(int course, vector<bool>& visited, vector<bool>& inStack) {
      if (inStack[course]) return false;
      if (visited[course]) return true;
      visited[course] = true;
      inStack[course] = true;
      
      for (const auto& depCourse : adjList[course]) {
        if (!util(depCourse, visited, inStack)) {
          return false;
        }
      }

      inStack[course] = false;
      return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      for (const auto& dep : prerequisites) {
        auto [it, success] = adjList.try_emplace(dep[1], vector<int>());
        it->second.emplace_back(dep[0]);
      }

      vector<bool> visited(numCourses, false);
      vector<bool> inStack(numCourses, false);
      for (int i = 0; i < numCourses; ++i) {
        if (!util(i, visited, inStack)) return false;
      }
      return true;
    }
};