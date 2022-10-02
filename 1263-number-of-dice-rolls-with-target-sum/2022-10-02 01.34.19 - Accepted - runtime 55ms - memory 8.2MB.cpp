class Solution {
    constexpr long int modulo() { return pow(10, 9) + 7; }
    vector<vector<int>> dp;
    int util(int n, int k, int target, int i, int sum) {
        if (sum > target) return 0;
        if (i == n) {
            if (sum == target) return 1;
            return 0;
        }
        
        // cout<<"i: "<<i<<", sum: "<<sum<<endl;
        
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
        dp.resize(n, vector<int>(target + 1, -1));
        return util(n, k, target, 0, 0);
    }
};