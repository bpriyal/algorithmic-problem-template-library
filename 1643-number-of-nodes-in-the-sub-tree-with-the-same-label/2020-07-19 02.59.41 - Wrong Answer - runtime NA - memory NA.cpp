class Solution {
    vector<vector<int>> adj;
    vector<int> result;
    vector<vector<int>> dp;
    int dfs(int i,char c,const string &labels,vector<bool> &visited) {
        if (visited[i]) return 0;
        visited[i] = true;
        if (dp[i][c-'a'] != -1) {
            return dp[i][c-'a'];
        }
        int count = 0;
        if (labels[i] == c) {
            ++count;
        }
        for(auto &x:adj[i]) {
            count += dfs(x,c,labels,visited);
        }
        dp[i][c-'a'] = count;
        visited[i] = false;
        return count;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.resize(n);
        if (n == 0) return result;
        vector<bool> visited(n,false);
        for(auto &x:edges) {
            adj[x[1]].push_back(x[0]);
            adj[x[0]].push_back(x[1]);
        }
        dp.resize(n);
        for(int i = 0;i<n;++i) {
            dp[i].resize(26,-1);
        }
        for (int i = 0;i<n;++i) {
            result.push_back(dfs(i,labels[i],labels,visited));
            visited[i] = true;
        }
        return result;
    }
};