class Solution {
    int util(int root,vector<vector<int>> &adj,int n,vector<bool> &visited) {
        if (visited[root]) {
            return n-1;
        }
        visited[root] = true;
        int localMax = INT_MIN;
        for(int x:adj[root]) {
            localMax = max(localMax,util(x,adj,n+1,visited));
        }
        visited[root] = false;
        return localMax;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return vector<int>(1,0);
        }
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        for(auto &vec:edges) {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        
        int result = INT_MAX;
        vector<int> cache(n);
        for(int i = 0;i < n;++i) {
           cache[i] = util(i,adj,0,visited);
        }
        
        int minEle = *min_element(cache.begin(),cache.end());
        vector<int> res;
        for(int i = 0;i < cache.size();++i) {
            if (cache[i] == minEle) {
                res.push_back(i);
            }
        }
        return res;
    }
};