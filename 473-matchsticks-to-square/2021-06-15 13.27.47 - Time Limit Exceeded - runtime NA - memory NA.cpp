class Solution {
    vector<int> sides;
    int size;
    int target;
    bool util(const vector<int> &matchsticks,int i) {
        if (i == size) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        
        for(int j = 0;j < 4;++j) {
            if (sides[j] + matchsticks[i] > target/4) {
                continue;
            }
            sides[j] += matchsticks[i];
            if (util(matchsticks,i+1)) {
                return true;
            }
            sides[j] -= matchsticks[i];
        }
        
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        sides.resize(4,0);
        size = matchsticks.size();
        target = 0;
        for(int i = 0;i < size;++i) {
            target += matchsticks[i];
        }
        if (target%4 != 0) {
            return false;
        }
        return util(matchsticks,0);
    }
};