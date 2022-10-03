class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        colors += ".";
        neededTime.push_back(0);
        int size = colors.size();
        int result = 0;
        
        int _sum = 0;
        int _max = 0;
        for (int i = 0; i < size; ++i) {
            _sum += neededTime[i];
            _max = max(_max, neededTime[i]);
            
            if (colors[i] != colors[i+1]) {
                if (_sum != neededTime[i]) {
                    result += _sum - _max;
                }
                _sum = 0;
                _max = 0;
            }
        }
                
        return result;
    }
};