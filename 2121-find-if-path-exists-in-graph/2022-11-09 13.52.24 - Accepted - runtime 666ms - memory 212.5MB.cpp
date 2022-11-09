class Solution {
    bool util(vector<vector<int>>& cache, int source, int destination, vector<bool>& visited) {
        if (source == destination) return true;
        if (visited[source]) return false;

        visited[source] = true;

        for (int node : cache[source]) {
            if (util(cache, node, destination, visited)) return true;
        }

        //visited[source] = false;

        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> cache(n, vector<int>());

        for (const auto& edge : edges) {
            cache[edge[0]].emplace_back(edge[1]);
            cache[edge[1]].emplace_back(edge[0]);
        }

        vector<bool> visited(n, false);
        return util(cache, source, destination, visited);
    }
};