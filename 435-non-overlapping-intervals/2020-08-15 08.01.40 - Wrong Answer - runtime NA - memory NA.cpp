class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size == 0) {
            return 0;
        }
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b) {
            return a[0] < b[0];
        });
        int result = 0;
        for(int i = 0;i<size-1;++i) {
            if (intervals[i][0] == intervals[i+1][0]) {
                if (intervals[i][1] < intervals[i+1][1]) {
                    swap(intervals[i],intervals[i+1]);
                }
                ++result;
            }
        }
        return result;
    }
};