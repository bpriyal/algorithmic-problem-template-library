// class Solution {
//     vector<vector<int>> _graph;
//     bool _leadsToDestination(int path, int destination, vector<int>& visited) {
//         if (visited[path] != 0) return visited[path] == 2;
//         if (_graph[path].empty()) return path == destination;
//         visited[path] = 1;
//         for (int subPath : _graph[path]) {
//             if (!_leadsToDestination(subPath, destination, visited)) {
//                 cout<<subPath<<endl;
//                 return false;
//             }
//         }
//         visited[path] = 2;
//         return true;
//     }
// public:
//     bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
//         _graph.resize(n, vector<int>());
//         for (const auto& edge : edges) {
//             if (edge[0] == edge[1]) return false;
//             _graph[edge[0]].emplace_back(edge[1]);
//         }
//         if (_graph[source].empty()) return source == destination;
//         for (int subPath : _graph[source]) {
//             vector<int> visited(n, 0);
//             if (!_leadsToDestination(subPath, destination, visited)) return false;
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool dfs(int curr, int target, unordered_map<int, vector<int>>& g,
            vector<int>& color) {
        // if it is a terminal/leaf node, then condition is satisfied only
        // if it is the target node
        if(g[curr].empty())
            return curr == target;
        
        // processing curr node
        color[curr] = 0;
        
        for(auto neighbor: g[curr]) {
            // node is currently processing and
            // we have again encountered it, so a cycle is present
            if(color[neighbor] == 0)
                return false;
            // recurse the path if the neighbor is unprocessed
            if(color[neighbor] == -1 && !dfs(neighbor, target, g, color))
                return false;
        }
        // node processed
        color[curr] = 1;
        
        return true;
    }
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        // create the graph
        unordered_map<int, vector<int> > g;
        
        for(auto edge: edges)
            g[edge[0]].push_back(edge[1]);
        
        // -1 is unprocessed, 0: processing, 1: processed
        vector<int> color(n, -1);
        
        return dfs(source, destination, g, color);
    }
};