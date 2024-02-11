class Solution {
    int _rows, _cols;
    int inf = 2147483647;
    int dfs(int i, int j, vector<vector<int>>& rooms) {
        // cout<<i<<"**"<<j<<endl;
        if (i < 0 || i >= _rows || j < 0 || j >= _cols || rooms[i][j] == -1 || rooms[i][j] == -2) return INT_MAX;
        if (rooms[i][j] == 0) return 0;
        if (rooms[i][j] != inf) return rooms[i][j];
        rooms[i][j] = -2;
        vector<pair<int, int>> possibleMoves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int distance = INT_MAX;
        for (const auto& move : possibleMoves) {
            distance = min(dfs(i + move.first, j + move.second, rooms), distance);
        }
        rooms[i][j] = inf;
        if (distance == INT_MAX) {
            // rooms[i][j] = -1;
            return INT_MAX;
        } else {
            // rooms[i][j] = distance + 1;
            return distance + 1;
        }
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        _rows = rooms.size();
        _cols = rooms[0].size();
        std::queue<pair<int, int>> q;
        vector<pair<int, int>> possibleMoves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _cols; ++j) {
                if (rooms[i][j] == 0) {
                    q.emplace(i, j);
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto gate = q.front(); q.pop();
                for (const auto& move : possibleMoves) {
                    int r = gate.first + move.first;
                    int c = gate.second + move.second;
                    if (r < 0 || r >= _rows || c < 0 || c >= _cols || rooms[r][c] != inf) continue;
                    rooms[r][c] = rooms[gate.first][gate.second] + 1;
                    q.emplace(r, c);
                }
            }
        }
    }
};