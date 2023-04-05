class Solution {
    int _k = 10001;

    void dfs(const vector<vector<int>>& adj, vector<bool>& visited, int stone) {
        visited[stone] = true;

        for (auto it : adj[stone]) {
            if (!visited[it]) {
                dfs(adj, visited, it);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int size = stones.size();
        vector<vector<int>> adj(2 * _k + 1, vector<int>());
        vector<bool> visited(2 * _k + 1);

        for (int i = 0; i < size; ++i) {
            int x = stones[i][0];
            int y = stones[i][1] + _k;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int components = 0;
        for (int i = 0; i < 2 * _k + 1; ++i) {
            if (!visited[i] && !adj[i].empty()) {
                ++components;
                dfs(adj, visited, i);
            }
        }

        return size - components;
    }
};