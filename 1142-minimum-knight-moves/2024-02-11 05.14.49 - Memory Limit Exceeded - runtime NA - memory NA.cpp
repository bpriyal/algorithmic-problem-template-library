class Solution {
    // unordered_map<pair<int, int>, int> _visited;
    // int dfs(int xDest, int yDest, int xCurr, int yCurr) {
    //     if (_visited.contains({xCurr, yCurr})) return _visited[{xCurr, yCurr}];
    //     if (xDest == xCurr && yDest == yCurr) return 0;
    //     vector<vector<int>> possibleMoves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    //                                          {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    //     int minMoves = INT_MAX;
    //     for (const auto& move : possibleMoves) {
    //         minMoves = min(dfs(xDest, yDest, xCurr + move[0], yCurr + move[1]), minMoves);
    //     }
    //     return minMoves 
    // }
public:
    int minKnightMoves(int x, int y) {
        vector<vector<int>> possibleMoves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                                             {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        std::queue<pair<int, int>> bfsQueue;
        bfsQueue.emplace(0, 0);
        int minMoves = -1;

        while (!bfsQueue.empty()) {
            int size = bfsQueue.size();
            cout<<size<<endl;
            ++minMoves;
            for (int i = 0; i < size; ++i) {
                auto location = bfsQueue.front();
                bfsQueue.pop();
                if (location.first == x && location.second == y) return minMoves;
                for (const auto& move : possibleMoves) {
                    bfsQueue.emplace(location.first + move[0], location.second + move[1]);
                }
            }
        }
        return -1;
    }
};