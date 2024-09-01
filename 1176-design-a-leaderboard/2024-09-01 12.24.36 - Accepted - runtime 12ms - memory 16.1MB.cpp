class Leaderboard {
    unordered_map<int, int> playerToScore;
    set<pair<int, int>> scorePlayerPairSet;
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        scorePlayerPairSet.erase({playerToScore[playerId], playerId});
        playerToScore[playerId] += score;
        scorePlayerPairSet.insert({playerToScore[playerId], playerId});
    }
    
    int top(int K) {
        int result = 0;
        int count = 0;
        for (auto it = scorePlayerPairSet.rbegin(); it != scorePlayerPairSet.rend() && count < K; ++it) {
          result += it->first;
          ++count;
        }
        return result;
    }
    
    void reset(int playerId) {
        scorePlayerPairSet.erase({playerToScore[playerId], playerId});
        playerToScore.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */