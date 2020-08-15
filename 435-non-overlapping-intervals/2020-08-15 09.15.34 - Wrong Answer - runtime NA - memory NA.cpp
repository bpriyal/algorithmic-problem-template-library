class Solution {
    int size;
    int comp(vector<vector<int>> &intervals,int pos,int n,int prev) {
        //cout<<pos<<endl;
        if (pos == size-1) {
            return n;
        }
        if (intervals[pos+1][0] < intervals[prev][1]) {
            //cout<<pos<<endl;
            int a = comp(intervals,pos+1,n+1,pos);
            
            //swap(intervals[pos],intervals[pos+1]);
            int b = comp(intervals,pos+1,n+1,pos+1);
            
            //swap(intervals[pos],intervals[pos+1]);
            return min(a,b);
        }
        return comp(intervals,pos+1,n,pos+1);
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
        
        return comp(intervals,0,0,0);
    }
};