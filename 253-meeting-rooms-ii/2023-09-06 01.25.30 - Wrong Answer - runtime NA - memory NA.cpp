class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](const auto& interval1, const auto& interval2) {
            return interval1[0] < interval2[0];
        });
        int minRooms = 0;
        stack<int> st;
        st.emplace(intervals[0][1]);
        cout<<"here"<<endl;
        for (int i = 1; i < size; ++i) {
            while (!st.empty() && intervals[i][0] >= st.top()) st.pop();
            st.emplace(intervals[i][1]);
            minRooms = max(minRooms, static_cast<int>(st.size()));
        }
        return minRooms;
    }
};