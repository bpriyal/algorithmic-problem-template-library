class Solution {
    vector<unsigned int> dp;
    int util(const vector<int> &nums,int target) {
        if(target == 0) {
            return 1;
        }
        
        if (dp[target] != -1) {
            return dp[target];
        }
        
        int temp = 0;
        for(int num:nums) {
            if (num > target) {
                break;
            } else {
                temp += util(nums,target-num);
            }
        }
        
        dp[target] = temp;
        return temp;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        dp.resize(target+1,0);
        dp[0] = 1;
        
        //return util(nums,target);
        int size = nums.size();
        
        for(int i = 1;i <= target;++i) {
            for(int num:nums) {
                if (num <= i) {
                    dp[i] += dp[i-num];
                } else {
                    break;
                }
            }
        }
        
        return dp[target];
    }
};