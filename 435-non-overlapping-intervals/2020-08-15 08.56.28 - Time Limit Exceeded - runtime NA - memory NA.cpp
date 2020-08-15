class Solution {
    int size;
    int comp(vector<vector<int>> &intervals,int pos,int n) {
        //cout<<pos<<endl;
        if (pos == size-1) {
            return n;
        }
       // cout<<intervals[pos+1][0]<<" "<<intervals[pos-prev][1]<<endl;
        if (intervals[pos+1][0] < intervals[pos][1]) {
            //cout<<pos<<endl;
            int a = comp(intervals,pos+1,n+1);
            //printf("interval:%d,%d\n",intervals[pos][0],intervals[pos][1]);
            swap(intervals[pos],intervals[pos+1]);
            //printf("after interval:%d,%d\n",intervals[pos][0],intervals[pos][1]);
            int b = comp(intervals,pos+1,n+1);
            swap(intervals[pos],intervals[pos+1]);
            return min(a,b);
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