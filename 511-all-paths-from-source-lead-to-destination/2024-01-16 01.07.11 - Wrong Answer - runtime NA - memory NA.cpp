class Solution {
    vector<vector<int>> _graph;
    bool _leadsToDestination(int path, int destination, vector<int>& visited) {
        if (_graph[path].empty()) return path == destination;
        if (visited[path] != 0) return visited[path] == 2;
        visited[path] = 1;
        for (int subPath : _graph[path]) {
            if (!_leadsToDestination(subPath, destination, visited)) {
                cout<<subPath<<endl;
                return false;
            }
        }
        visited[path] = 2;
        return true;
    }
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        _graph.resize(n, vector<int>());
        for (const auto& edge : edges) {
            if (edge[0] == edge[1]) return false;
            _graph[edge[0]].emplace_back(edge[1]);
        }
        // if (_graph[source].empty()) return false;
        for (int subPath : _graph[source]) {
            vector<int> visited(n, 0);
            if (!_leadsToDestination(subPath, destination, visited)) return false;
        }
        return true;
    }
};