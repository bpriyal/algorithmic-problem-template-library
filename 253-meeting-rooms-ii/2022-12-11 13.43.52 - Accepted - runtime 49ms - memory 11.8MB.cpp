class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        priority_queue<int, vector<int>, greater<int>> q;
        int maxConferenceRooms = 0;

        for (int i = 0; i < intervals.size(); ++i) {
            if (!q.empty()) cout<<q.top()<<endl;
            if (!q.empty() && q.top() <= intervals[i][0]) {
                cout<<i<<", "<<q.top()<<endl;
                q.pop();
            } else {
                ++maxConferenceRooms;
            }
            q.push(intervals[i][1]);
        }

        return maxConferenceRooms;
    }
};