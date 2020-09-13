class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int open = 0;
        int size = intervals.size();
        vector<vector<int>> result;
        if (size == 0) {
            result.push_back(newInterval);
            return result;
        }
        for(int i = 0;i<size;++i) {
            if ((intervals[i][0] >= newInterval[0] && intervals[i][0] <= newInterval[1]) ||
                (intervals[i][1] >= newInterval[0] && intervals[i][1] <= newInterval[1])) {
                newInterval[0] = min(intervals[i][0],newInterval[0]);
                newInterval[1] = max(intervals[i][1],newInterval[1]);
                open = 1;
            } else {
                if (open==1) {
                    open = 2;
                    result.push_back(newInterval);
                }
                result.push_back(intervals[i]);
            }
            if (newInterval[0] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) {
                open = 3;
            }
        }
        if (open==0 || open == 1) {
            result.push_back(newInterval);
        }
        sort(result.begin(),result.end(),[](const vector<int> &a,const vector<int> &b){
            return a[0] < b[0];
        });
        return result;
    }
};