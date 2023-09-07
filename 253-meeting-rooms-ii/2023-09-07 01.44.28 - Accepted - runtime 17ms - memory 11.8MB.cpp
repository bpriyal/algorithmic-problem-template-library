class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& interval1, const auto& interval2) {
            return interval1[0] < interval2[0];
        });
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int minRooms = 0;

        for (const auto& interval : intervals) {
            while (!pq.empty() && pq.top() <= interval[0]) {
                pq.pop();
            }
            pq.emplace(interval[1]);
            minRooms = max(minRooms, static_cast<int>(pq.size()));
        }
        return minRooms;
    }
};