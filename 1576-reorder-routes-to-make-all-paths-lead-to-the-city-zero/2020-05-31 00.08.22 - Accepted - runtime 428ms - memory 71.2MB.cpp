class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> adj;
    int count;
    
    bool dfs(int i) {
        bool flag = false;
        if (visited[i] || i==0) return true;
        for(auto &x:adj[i]) {
            if (dfs(x)) {
                flag = true;
                break;
            }
        }
        visited[i] = true;
        if (flag) {
            return true;
        } else {
            ++count;
            return false;
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        visited.resize(n,false);
        for (auto &x:connections) {
            adj[x[0]].push_back(x[1]);
        }
        for(int i=1;i<n;++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return count;
    }
};