class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int size = asteroids.size();
        vector<int> result;
        
        for(int i = 0; i < size; ++i) {
            if (result.empty() || asteroids[i] > 0 || result.back() < 0) result.push_back(asteroids[i]);
            else {
                if (abs(result.back()) > abs(asteroids[i])) continue;
                
                if (abs(result.back()) < abs(asteroids[i])) {
                    --i;
                }
                result.pop_back();
            }
        }
        
        return result;
    }
};