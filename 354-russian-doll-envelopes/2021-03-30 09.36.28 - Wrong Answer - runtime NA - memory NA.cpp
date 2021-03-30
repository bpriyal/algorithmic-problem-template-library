class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(begin(envelopes),end(envelopes),[](const vector<int> &a,const vector<int> &b) {
           if (a[0] < b[0]) {
               return true;
           } else if (a[0] == b[0]) {
               return a[1] < b[1];
           } else {
               return false;
           }
        });
        
        vector<int> temp = {envelopes[0][0],envelopes[0][1]};
        int count = 1;
        
        for(int i = 1;i <envelopes.size();++i) {
            if (temp[0] < envelopes[i][0] && temp[1] < envelopes[i][1]) {
                temp = {envelopes[i][0],envelopes[i][1]};
                ++count;
            }
        }
        
        return count;
    }
};