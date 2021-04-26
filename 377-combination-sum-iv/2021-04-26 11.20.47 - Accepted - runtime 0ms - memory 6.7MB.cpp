class Solution {
    int result;
    vector<int> dp;
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
        //cout<<temp<<endl;
        dp[target] = temp;
        return temp;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        result = 0;
        sort(nums.begin(),nums.end());
        dp.resize(target+1,-1);
        
        return util(nums,target);
    }
};