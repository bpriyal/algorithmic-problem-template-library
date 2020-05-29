class Solution {
public:
    vector<vector<int>> adjmat;
    vector<int> visited;
    bool dfs(int i) {
        if (visited[i] == 1) {
            return false;
        }
        visited[i] = 1;
        for (auto &x:adjmat[i]) {
            if(!dfs(x)) return false;
        }
        visited[i] = 2;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adjmat.resize(numCourses);
        unordered_set<int> s;
        visited.resize(numCourses,false);
        for (auto &x:prerequisites) {
            adjmat[x[0]].push_back(x[1]);
            s.insert(x[0]);
        }
        for (auto &x:s) {
            if (!visited[x]) {
                if(!dfs(x)) return false;
            }
        }
        return true;
    }
};