class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<pair<int,int>> cache({{0,1},{1,0},{0,-1},{-1,0}});
        int angle = 0;
        pair<int,int> position = {0,0};
        for(auto c:instructions) {
            switch(c) {
                case 'L':
                    angle = (angle+3)%4;
                    break;
                case 'R':
                    angle = (angle+1)%4;
                    break;
                case 'G':
                    position.first += cache[angle].first;
                    position.second += cache[angle].second;
            }
        }
        return (angle == 0 || (position.first == 0 && position.second ==0));
    }
};