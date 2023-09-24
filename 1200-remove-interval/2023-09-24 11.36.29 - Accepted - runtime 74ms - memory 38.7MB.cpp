class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int intervalSize = intervals.size();
        int toBeRemovedSize = toBeRemoved.size();
        vector<vector<int>> result;
        for (int i = 0; i < intervalSize; ++i) {
             if (intervals[i][1] < toBeRemoved[0] || intervals[i][0] > toBeRemoved[1]) {
                result.emplace_back(intervals[i]);
             }
             if (intervals[i][0] <= toBeRemoved[0] && intervals[i][1] >= toBeRemoved[1]) {
                 if (intervals[i][0] != toBeRemoved[0]) result.emplace_back(vector<int>{intervals[i][0], toBeRemoved[0]});
                 if (intervals[i][1] != toBeRemoved[1]) result.emplace_back(vector<int>{toBeRemoved[1], intervals[i][1]});
                 continue;
             }
             if (toBeRemoved[1] >= intervals[i][0] && toBeRemoved[1] < intervals[i][1]) {
                 result.emplace_back(vector<int>{toBeRemoved[1], intervals[i][1]});
             }
             if (toBeRemoved[0] > intervals[i][0] && toBeRemoved[0] <= intervals[i][1]) {
                 result.emplace_back(vector<int>{intervals[i][0], toBeRemoved[0]});
             }
        }
        return result;
    }
};