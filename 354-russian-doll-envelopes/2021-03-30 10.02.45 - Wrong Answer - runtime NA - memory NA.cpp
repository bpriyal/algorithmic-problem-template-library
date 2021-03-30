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
        
        int size = envelopes.size();
        vector<int> dp(size+1,1);
        
        for(int i = 1;i < size;++i) {
            for(int j = i-1;j >= 0;--j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }
        
        return dp[size-1];
    }
};