class Solution {
    int size;
    int comp(vector<vector<int>> &intervals,int pos,int n,int prev) {
        //cout<<pos<<endl;
        if (pos == size-1) {
            return n;
        }
       // cout<<intervals[pos+1][0]<<" "<<intervals[pos-prev][1]<<endl;
        if (intervals[pos+1][0] < intervals[pos-prev][1]) {
            //cout<<pos<<endl;
            return min(comp(intervals,pos+1,n+1,1),comp(intervals,pos+1,n+1,0));
        }
        return comp(intervals,pos+1,n,0);
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
        //cout<<"here"<<endl;
        return comp(intervals,0,0,0);
    }
};