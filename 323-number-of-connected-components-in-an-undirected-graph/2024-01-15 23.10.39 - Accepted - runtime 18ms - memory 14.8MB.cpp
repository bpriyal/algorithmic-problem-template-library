class Solution {
    vector<vector<int>> _graph;
    vector<bool> _visited;
    void _countComponents(int n) {
        if (_visited[n]) return;
        _visited[n] = true;
        for (int sub : _graph[n]) {
            _countComponents(sub);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        _graph.resize(n, vector<int>());
        _visited.resize(n, false);
        int result = 0;
        for (const auto& edge : edges) {
            _graph[edge[0]].emplace_back(edge[1]);
            _graph[edge[1]].emplace_back(edge[0]);
        }
        for (int i = 0; i < n; ++i) {
            if (!_visited[i]) {
                ++result;
                _countComponents(i);
            }
        }
        return result;
    }
};