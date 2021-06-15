class Solution {
    vector<int> sides;
    int size;
    bool util(const vector<int> &matchsticks,int i) {
        if (i == size) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        
        for(int j = 0;j < 4;++j) {
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
        return util(matchsticks,0);
    }
};