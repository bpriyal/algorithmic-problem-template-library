class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& interval1, const auto& interval2) {
            return interval1[0] < interval2[0];
        });

        for (int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i+1].front() <= intervals[i].back()) return false;
        }
        return true;
    }
};