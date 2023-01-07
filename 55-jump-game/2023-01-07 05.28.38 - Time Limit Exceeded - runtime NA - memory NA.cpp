class Solution {
    int size;
    vector<int> dp;
    bool util(const vector<int>& nums, int currPos) {
        if (currPos >= size - 1) return true;

        if (dp[currPos] != -1) return dp[currPos];

        for (int i = 1; i <= nums[currPos]; ++i) {
            if (util(nums, currPos + i)) {
                dp[currPos] = 1;
                return true;
            }
        }
        dp[currPos] = 0;
        return dp[currPos];
    }
public:
    bool canJump(vector<int>& nums) {
        size = nums.size();
        dp.resize(size, 0);
        //return util(nums, 0);

        dp[size - 1] = 1;

        for (int i = size - 2; i >= 0; --i) {
            for (int jump = 1; jump <= nums[i]; ++jump) {
                int dest = i + jump;
                if (dest >= size -1 ) dp[i] = 1;
                else dp[i] = dp[dest];

                if (dp[i] == 1) break;
            }
            cout<<"i: "<<i<<", dp[i]: "<<dp[i]<<endl;
        }

        return dp[0];
    }
};