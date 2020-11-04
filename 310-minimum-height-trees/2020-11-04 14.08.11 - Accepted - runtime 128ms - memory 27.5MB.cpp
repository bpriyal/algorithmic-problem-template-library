class Solution {
    vector<int> dp;
    int util(int root,vector<vector<int>> &adj,int n,vector<bool> &visited) {
        if (visited[root]) {
            return n-1;
        }
        if (dp[root] != 0) {
            return dp[root];
        }
        visited[root] = true;
        int localMax = INT_MIN;
        for(int x:adj[root]) {
            localMax = max(localMax,util(x,adj,n+1,visited));
        }
        visited[root] = false;
        dp[root] = localMax;
        return localMax;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        /*if (n == 1) {
            return vector<int>(1,0);
        }
        vector<vector<int>> adj(n);
        dp.resize(n);
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
        return res;*/
        if(n < 2) return {0};
        vector<vector<int>> g(n);
        vector<int> indegrees(n, 0);
        for(const auto& e: edges){
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
            indegrees[e[0]]++;
            indegrees[e[1]]++;
        }        
     
        vector<int> q, level;
        for(int i = 0; i < n; i++)
            if(indegrees[i] == 1) q.emplace_back(i);
        for(int step = 0; !q.empty(); ++step){            
            for(int sz = q.size(); sz > 0; sz--){                
                auto cur = q[sz - 1];
                for(const auto& next: g[cur])
                    if(--indegrees[next] == 1)
                        level.emplace_back(next);
            }            
            if(level.empty()) break;
            swap(q, level);level.clear();
        }
        return q;
    }
};