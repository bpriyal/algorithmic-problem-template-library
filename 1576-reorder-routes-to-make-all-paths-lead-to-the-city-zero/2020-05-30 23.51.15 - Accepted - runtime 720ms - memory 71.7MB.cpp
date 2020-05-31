class Solution {
public:
    vector<int> visited;
    vector<vector<int>> adj;
    int count;
    
    bool dfs(int i) {
        bool flag = false;
        if (visited[i] ==2 || i==0) return true;
        visited[i] = 1;
        for(auto &x:adj[i]) {
            if (dfs(x)) {
                flag = true;
                break;
            }
        }
        if (flag) {
            visited[i] = 2;
            return true;
        } else {
            ++count;
            visited[i] = 2;
            return false;
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        visited.resize(n,-1);
        for (auto &x:connections) {
            adj[x[0]].push_back(x[1]);
        }
        for(int i=1;i<n;++i) {
            if (visited[i] != 2) {
                dfs(i);
            }
        }
        return count;
    }
};