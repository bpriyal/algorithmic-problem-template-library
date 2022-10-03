class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int size = colors.size();
        int result = 0;
        
        int runningSum = 0;
        int runningMax = 0;
        for (int i = 1; i < size; ++i) {
            cout<<i<<endl;
            if (colors[i-1] == colors[i]) {
                runningSum += neededTime[i-1] + neededTime[i];
                runningMax = max({runningMax, neededTime[i-1], neededTime[i]});
            } else {
                cout<<runningSum<<", "<<runningMax<<endl;
                result += runningSum - runningMax;
                runningSum = runningMax = 0;
            }
        }
        
        result += runningSum - runningMax;
        
        return result;
    }
};