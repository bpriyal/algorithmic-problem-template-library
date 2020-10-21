class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int size = asteroids.size();
        vector<int> result;
        if (size == 0) {
            return result;
        }
        result.push_back(asteroids[0]);
        for(int i = 1;i < size;++i) {
            if (asteroids[i] >= 0) {
                result.push_back(asteroids[i]);
            } else {
                if (result.size() == 0) {
                    result.push_back(asteroids[i]);
                    continue;
                }
                if (asteroids[i] + result.back() == 0) {
                    result.pop_back();
                    continue;
                }
                if (result.back() >= 0 && abs(asteroids[i]) > result.back()) {
                    result.pop_back();
                    result.push_back(asteroids[i]);
                    int j = result.size() - 1;
                    while(j >= 0) {
                        if (result[j] < 0 && result[j-1] >= 0) {
                            if (abs(result[j]) > result[j-1]) {
                                int temp = result[j];
                                result.pop_back();
                                result.pop_back();
                                result.push_back(temp);
                            } else {
                                result.pop_back();
                            }
                        } else {
                            break;
                        }
                        j = result.size()-1;
                    }
                } else if (result.back() < 0) {
                    result.push_back(asteroids[i]);
                }
            
            }
        }
        return result;
    }
};