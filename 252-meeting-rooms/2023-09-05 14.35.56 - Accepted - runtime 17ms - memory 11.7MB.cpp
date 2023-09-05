class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size <= 1) return true;

        sort(intervals.begin(), intervals.end(), [](const auto& interval1, const auto& interval2) {
            return interval1[0] < interval2[0];
        });
        for (int i = 0; i < size - 1; ++i) {
            if (intervals[i+1].front() < intervals[i].back()) return false;
        }
        return true;
    }
};