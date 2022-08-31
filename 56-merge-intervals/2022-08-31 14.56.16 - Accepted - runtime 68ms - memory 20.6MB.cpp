class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        vector<vector<int>> result;
        
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
           return a[0] < b[0]; 
        });
        
        result.push_back(intervals[0]);
        
        for (int i = 1; i < size; ++i) {
            auto curr = result.back();
            if (intervals[i][0] <= curr[1]) {
                result.pop_back();
                result.push_back({ curr[0], max(curr[1], intervals[i][1]) });
            } else result.push_back(intervals[i]);
        }
        
        return result;
    }
};