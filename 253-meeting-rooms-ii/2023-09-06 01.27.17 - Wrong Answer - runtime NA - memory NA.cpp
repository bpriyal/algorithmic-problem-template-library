class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size <= 1) return size;
        sort(intervals.begin(), intervals.end(), [](const auto& interval1, const auto& interval2) {
            if (interval1[0] < interval2[0]) return true;
            else if (interval1[0] == interval2[0]) return interval1[1] < interval2[1];
            else return false;
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