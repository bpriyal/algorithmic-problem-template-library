class Solution {
    constexpr long int modulo() { return pow(10, 9) + 7; }
    vector<vector<int>> dp;
    int util(int n, int k, int target, int i, int sum) {
        if (sum > target) return 0;
        if (i == n) {
            if (sum == target) return 1;
            return 0;
        }
                
        if (dp[i][sum] != -1) return dp[i][sum];
        
        int result = 0;
        
        for (int j = 1; j <= k; ++j) {
            result = (result + (util(n, k, target, i + 1, sum + j)) % modulo()) % modulo();
        }
        
        dp[i][sum] = result;
        return result;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        //dp.resize(n + 1, vector<int>(target + 1, -1));
        //return util(n, k, target, 0, 0);
        
        // for (int i = 0; i <= target; ++i) dp[0][i] = 0;
        // for (int i = 1; i <= n; ++i) dp[i][0] = 0;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            vector<int> temp(target + 1, 0);
            for (int j = 1; j <= k; ++j) {
                for (int t = j; t <= target; ++t) {
                    temp[t] = (temp[t] + dp[t-j] % modulo()) % modulo();
                }
            }
            swap(temp, dp);
        }
        
        return dp[target];
    }
};