class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int size = asteroids.size();
        vector<int> result;
        for(int i = 0;i < size;++i) {
            if (result.empty() || result.back() < 0 || asteroids[i] > 0) {
                result.push_back(asteroids[i]);
            } else if (result.back() <= abs(asteroids[i])) {
                if (result.back() < abs(asteroids[i])) {
                    --i;
                }
                result.pop_back();
            }
        }
        return result;
    }
};