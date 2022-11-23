class Solution {
    vector<bool> visited;
    int result;

    void util(const vector<vector<int>>& tree, int node) {
        if (visited[node]) return;

        visited[node] = true;
        ++result;

        for (auto n : tree[node]) {
            util(tree, n);
        }
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> tree(n, vector<int>());
        result = 0;
        visited.resize(n, false);

        for (auto& it : edges) {
            tree[it[0]].emplace_back(it[1]);
            tree[it[1]].emplace_back(it[0]);
        }

        for (int node : restricted) {
            visited[node] = true;
        }

        util(tree, 0);

        return result;
    }
};