class Solution {
    inline bool sameRowOrColumn(const vector<int>& stone1, const vector<int>& stone2) {
        return stone1[0] == stone2[0] || stone1[1] == stone2[1];
    }

    void dfs(const vector<vector<int>>& adj, vector<bool>& visited, int currentStone) {
        cout<<currentStone<<endl;
        if (currentStone == _size || visited[currentStone]) return;
        visited[currentStone] = true;

        for (int stone : adj[currentStone]) {
            dfs(adj, visited, stone);
        }
    }

    int _size;
public:
    int removeStones(vector<vector<int>>& stones) {
        int connectedComponents = 0;
        _size = stones.size();
        vector<vector<int>> adj(_size, vector<int>());
        vector<bool> visited(_size, false);

        for (int i = 0; i < _size; ++i) {
            for(int j = i + 1; j < _size; ++j) {
                if (sameRowOrColumn(stones[i], stones[j])) {
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }
        }
        cout<<"after"<<endl;

        for (int i = 0; i < _size; ++i) {
            if (!visited[i]) {
                ++connectedComponents;
                dfs(adj, visited, i);
            }
        }

        return _size - connectedComponents;
    }
};