class Solution {
    vector<vector<int>> adj;
    vector<int> result;
    vector<int> cache;
    void dfs(int i,const string &labels,vector<bool> &visited) {
        if (visited[i]) return;
        int counter = cache[labels[i]-'a'];
        ++cache[labels[i]-'a'];
        visited[i] = true;
        
        for(auto &x:adj[i]) {
            dfs(x,labels,visited);
        }
        
        result[i] = cache[labels[i]-'a'] - counter;
    }
public:
    Solution() {
        cache.resize(26,0);
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.resize(n);
        if (n == 0) return result;
        result.resize(n);
        vector<bool> visited(n,false);
        for(auto &x:edges) {
            adj[x[1]].push_back(x[0]);
            adj[x[0]].push_back(x[1]);
        }
        for (int i = 0;i<n;++i) {
            if (!visited[i])
                dfs(i,labels,visited);
        }
        return result;
    }
};