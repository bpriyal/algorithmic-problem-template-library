class Solution {
    void util(const vector<vector<int>>& graph, vector<bool>& visited, int i) {
        if (visited[i]) return;
        visited[i] = true;
        for (auto it : graph[i]) util(graph, visited, it);
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visited(n, false);
        int result = 0;

        for (auto it : edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++result;
                util(graph, visited, i);
            }
        }

        return result;
    }
};