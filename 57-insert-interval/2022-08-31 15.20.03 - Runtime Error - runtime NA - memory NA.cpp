class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int size = intervals.size();
        vector<vector<int>> result;
        
        if (!size) {
            result.push_back(newInterval);
            return result;
        }
        
        int i = 0;
        
        while (i < size) {
            if (newInterval[0] < intervals[i][0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
            ++i;
        }
        
        ++size;
        
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