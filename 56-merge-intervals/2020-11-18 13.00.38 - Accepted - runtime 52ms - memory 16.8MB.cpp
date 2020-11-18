class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size <= 1) {
            return intervals;
        }
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        int i = 1;
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        while(i < size) {
            /*cout<<i<<endl;
            for(int i = 0;i<result.size();++i) {
                printf("[%d,%d]\t",result[i][0],result[i][1]);
            }
            cout<<endl;*/
            vector<int> temp1 = result.back();
            result.pop_back();
            if (temp1[1] < intervals[i][0]) {
                result.push_back(temp1);
                result.push_back(intervals[i]);
            } else {
                vector<int> temp;
                temp.push_back(temp1[0]);
                temp.push_back(max(intervals[i][1],temp1[1]));
                result.push_back(temp);
            }
            ++i;
        }
        return result;
    }
};