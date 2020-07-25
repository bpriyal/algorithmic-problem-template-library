class Solution {
    vector<vector<int>> adj;
    vector<vector<int>> result;
    int n;
    void dfs(int i,vector<int> &temp) {
        if (i == n-1) {
            temp.push_back(i);
            result.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(i);
        for(auto &x:adj[i]) {
            dfs(x,temp);
        }
        temp.pop_back();
    } 
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        adj.resize(n);
        for(int i = 0;i<n;++i) {
            for(auto &x:graph[i]) {
                adj[i].push_back(x);
            }
        }
        vector<int> temp;
        dfs(0,temp);
        return result;
    }
};