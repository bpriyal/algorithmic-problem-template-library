class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        int count = size;
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b) {
           if (a[0] < b[0]) {
               return true;
           } else if (a[0] > b[0]) {
               return false;
           } else {
               return a[1] > b[1];
           }
        });
        
        for(int i = 0;i<size;++i) {
            int l = intervals[i][0];
            int r = intervals[i][1];
            for(int j = 0;j < i;++j) {
                if (intervals[j][0] <= l && intervals[j][1] >= r) {
                    --count;
                }
            }
        }
        return count;
    }
};