class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string &a,const string &b) {
            return a.size() < b.size();
        });
        
        unordered_map<string,int> dp;
        int result = INT_MIN;
        
        for(const string &s:words) {
            for(int i = 0;i < s.size();++i) {
                string temp = s.substr(0,i)+s.substr(i+1);
                dp[s] = max(dp[s],dp.find(temp) == dp.end()? 1:dp[temp]+1);
            }
            result = max(result,dp[s]);
        }
        
        return result;
    }
};