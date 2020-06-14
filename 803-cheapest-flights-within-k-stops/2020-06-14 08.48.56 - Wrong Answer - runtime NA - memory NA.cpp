class Solution {
    int dfs(int src,int dst,int k) {
        if (src == dst) return 0;
        if (k < 0) return 100000001;
        int _min = INT_MAX;
        for (auto& x: adj[src]) {
            _min = min(_min,x.second + dfs(x.first,dst,k-1));
        }
        return _min;
    }
public:
    vector<vector<pair<int,int>>> adj;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        adj.resize(n);
        for(auto &x:flights) {
            adj[x[0]].push_back(make_pair(x[1],x[2]));
        }
        return dfs(src,dst,K);
    }
};