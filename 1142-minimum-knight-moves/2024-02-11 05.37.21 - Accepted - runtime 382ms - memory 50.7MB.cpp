class Solution {
public:
    int minKnightMoves(int x, int y) {
        vector<vector<int>> possibleMoves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                                             {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        std::queue<pair<int, int>> bfsQueue;
        vector<vector<bool>> visited(607, vector<bool>(607, false));
        bfsQueue.emplace(0, 0);
        visited[0][0] = true;
        int minMoves = -1;

        while (!bfsQueue.empty()) {
            int size = bfsQueue.size();
            ++minMoves;
            for (int i = 0; i < size; ++i) {
                auto location = bfsQueue.front();
                bfsQueue.pop();
                if (location.first == x && location.second == y) return minMoves;
                for (const auto& move : possibleMoves) {
                    int newX = location.first + move[0];
                    int newY = location.second + move[1];
                    if (visited[newX + 302][newY + 302]) continue;
                    bfsQueue.emplace(newX, newY);
                    visited[newX + 302][newY + 302] = true;
                }
            }
        }
        return -1;
    }
};