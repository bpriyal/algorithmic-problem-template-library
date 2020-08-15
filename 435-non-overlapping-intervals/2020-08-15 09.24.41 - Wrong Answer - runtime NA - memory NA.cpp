class Solution {
    int size;
    int comp(vector<vector<int>> &intervals,int pos,int n) {
        //cout<<pos<<endl;
        if (pos == size-1) {
            return n;
        }
        if (intervals[pos+1][0] < intervals[pos][1]) {
            //cout<<pos<<endl;
            if (intervals[pos+1][1]-intervals[pos+1][0] > intervals[pos][1]-intervals[pos][0]) {
                swap(intervals[pos+1],intervals[pos]);
                return comp(intervals,pos+1,n+1);
            } else if (intervals[pos+1][1]-intervals[pos+1][0] < intervals[pos][1]-intervals[pos][0]){
                return comp(intervals,pos+1,n+1);
            } else {
                int a = comp(intervals,pos+1,n+1);
                swap(intervals[pos+1],intervals[pos]);
                int b = comp(intervals,pos+1,n+1);
                swap(intervals[pos+1],intervals[pos]);
                return min(a,b);
            }
        }
        return comp(intervals,pos+1,n);
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        size = intervals.size();
        if (size == 0) {
            return 0;
        }
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b) {
            return a[0] < b[0];
        });
        
        return comp(intervals,0,0);
    }
};