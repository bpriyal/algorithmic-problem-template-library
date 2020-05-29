class Solution {
public:
    vector<vector<int>> adjmat;
    vector<bool> visited;
    bool dfs(int i) {
        if (visited[i]) {
            cout<<i<<endl;
            return false;
        }
        visited[i] = true;
        for (auto &x:adjmat[i]) {
            if(!dfs(x)) return false;
        }
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