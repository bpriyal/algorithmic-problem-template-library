class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size == 1) return intervals;

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;

        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < size; ++i) {
            if (intervals[i][0] > end) {
                result.emplace_back(vector<int>{start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } else {
                end = max(end, intervals[i][1]);
            }
        }
        result.emplace_back(vector<int>{start, end});
        return result;
    }
};