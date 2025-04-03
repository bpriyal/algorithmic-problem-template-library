class Solution {
    unordered_map<int, vector<int>> adjList;
    bool util(int course, vector<bool>& visited) {
      if (visited[course]) return false;
      visited[course] = true;
      
      for (const auto& depCourse : adjList[course]) {
        if (!util(depCourse, visited)) {
          cout << "original course: " << course << ", dependent course: " << depCourse << endl;
          return false;
        }
      }
      return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      for (const auto& dep : prerequisites) {
        auto [it, success] = adjList.try_emplace(dep[0], vector<int>());
        it->second.emplace_back(dep[1]);
        cout << dep[0] << "->" << dep[1] << endl;
      }

      for (int i = 0; i < numCourses; ++i) {
        vector<bool> visited(numCourses);
        cout << i << endl;
        if (!util(i, visited)) return false;
      }
      return true;
    }
};