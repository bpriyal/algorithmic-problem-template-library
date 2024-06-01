class SnakeGame {
    std::queue<pair<int, int>> _snake;
    set<pair<int, int>> _snakeCache;
    int _width, _height;
    vector<vector<int>> _food;
    int _foodIdx;
    unordered_map<string, pair<int, int>> _direction = {
        {"R", {0, 1}},
        {"L", {0 , -1}},
        {"U", {-1, 0}}, 
        {"D", {1, 0}}
    };
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        _width = width;
        _height = height;
        _food = food;
        _foodIdx = 0;
        _snake.push({0, 0});
        _snakeCache.emplace(std::make_pair<int, int>(0, 0));
    }
    
    int move(string direction) {
        const auto& dir = _direction[direction];
        pair<int, int> newHead = { _snake.back().first + dir.first, _snake.back().second + dir.second };
        cout<<newHead.first<<", "<<newHead.second<<endl;
        // Check termination of game
        if (newHead.first < 0 || newHead.first >= _height || newHead.second < 0 || newHead.second >= _width) return -1;
        if (_snakeCache.count(newHead)) return -1;

        _snake.push(newHead);
        _snakeCache.emplace(newHead);

        if (newHead.first == _food[_foodIdx][0] && newHead.second == _food[_foodIdx][1]) {
            ++_foodIdx;
        } else {
            const auto& last = _snake.front();
            _snake.pop();
            _snakeCache.erase(last);
        }
        return _foodIdx;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */