class Solution {
    vector<vector<int>> _graph;
    bool _leadsToDestination(int path, int destination, vector<bool>& visited) {
        if (visited[path]) return false;
        if (path == destination) return true;
        if (_graph[path].empty()) return false;
        visited[path] = true;
        for (int subPath : _graph[path]) {
            if (!_leadsToDestination(subPath, destination, visited)) {
                cout<<subPath<<endl;
                return false;
            }
        }
        return true;
    }
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        _graph.resize(n, vector<int>());
        for (const auto& edge : edges) {
            if (edge[0] == edge[1]) return false;
            _graph[edge[0]].emplace_back(edge[1]);
        }
        if (_graph[source].empty()) return false;
        vector<bool> visited(n, false);
        for (int subPath : _graph[source]) {
            visited.clear();
            visited[source] = true;
            if (!_leadsToDestination(subPath, destination, visited)) return false;
        }
        return true;
    }
};