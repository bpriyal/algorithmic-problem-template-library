class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
      int size = intervals.size();
      sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
      });

      priority_queue<int, vector<int>, greater<int>> pq;
      int meetingRooms = 0;

      for (const auto& interval : intervals) {
        if (!pq.empty() && pq.top() <= interval[0]) pq.pop();
        pq.emplace(interval[1]);
        meetingRooms = max(meetingRooms, static_cast<int>(pq.size()));
      }
      return meetingRooms;
    }
};