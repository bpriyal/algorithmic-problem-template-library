class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int size = days.size();
        unordered_map<int,int> cache;
        for(int i = 0;i<size;++i) {
            cache[days[i]]++;
        }
        vector<int> dp(days[size-1]+1);
        dp[0]=0;
        for(int i = 1;i<=days[size-1];++i) {
            //cout<<i<<endl;
            if (cache.find(i) != cache.end()) {
                dp[i] = min({dp[max(0,i-1)]+costs[0],dp[max(0,i-7)]+costs[1],dp[max(0,i-30)]+costs[2]});
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[days[size-1]];
    }
};