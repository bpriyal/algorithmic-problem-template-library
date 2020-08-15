class Solution {
    int size;
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        size = intervals.size();
        if (size == 0) {
            return 0;
        }
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b) {
            return a[0] < b[0];
        });
        int count = 0;
        for(int i=0;i<size-1;++i) {
            if (intervals[i+1][0] < intervals[i][1]) {
                ++count;
                if (intervals[i+1][1] > intervals[i][1]) {
                    swap(intervals[i+1],intervals[i]);
                }
            }
        }      
        return count;
    }
};