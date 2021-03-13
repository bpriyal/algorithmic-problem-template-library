class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int div = pow(10,9) + 7;
        unordered_map<int,long> dp;
        int res = 0;
        
        for(int i = 0;i < arr.size();++i) {
            dp[arr[i]] = 1;
            for(int j = 0;j < i;++j) {
                if (arr[i]%arr[j] == 0) {
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i]/arr[j]]) % div;
                }
            }
            res = (res + dp[arr[i]]) % div;
        }
        
        return res;
    }
};