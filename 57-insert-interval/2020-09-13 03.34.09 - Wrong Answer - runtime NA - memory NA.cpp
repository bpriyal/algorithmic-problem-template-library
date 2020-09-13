class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool open = false;
        int size = intervals.size();
        vector<vector<int>> result;
        if (size == 0) {
            result.push_back(newInterval);
            return result;
        }
        for(int i = 0;i<size;++i) {
            if ((intervals[i][0] >= newInterval[0] && intervals[i][0] <= newInterval[1]) ||
                (intervals[i][1] >= newInterval[0] && intervals[i][1] <= newInterval[1])) {
                newInterval[0] = min(intervals[i][0],newInterval[0]);
                newInterval[1] = max(intervals[i][1],newInterval[1]);
                open = true;
            } else {
                if (open) {
                    open = false;
                    result.push_back(newInterval);
                }
                result.push_back(intervals[i]);
            }
        }
        if (open) {
            result.push_back(newInterval);
        }
        return result;
    }
};