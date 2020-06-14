class Solution {
    int cache[100][100][100] ={0};
    int dfs(int src,int dst,int k) {
        if (src == dst) return 0;
        if (k < 0) return 10000001;
        int _min = 10000001;
        if (cache[src][dst][k]) return cache[src][dst][k];
        for (auto& x: adj[src]) {
            _min = min(_min,x.second + dfs(x.first,dst,k-1));
        }
        cache[src][dst][k] = _min;
        return _min;
    }
public:
    vector<vector<pair<int,int>>> adj;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        adj.resize(n);
        for(auto &x:flights) {
            adj[x[0]].push_back(make_pair(x[1],x[2]));
        }
        int result = dfs(src,dst,K);
        return result > 10000001? -1:result;
    }
};