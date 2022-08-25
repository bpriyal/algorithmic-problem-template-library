class Solution {
    int size;
    int sum;
    bool util(vector<int>& nums, int set1, int i) {
        if (set1 == sum/2) return true;
        if (set1 > sum/2 || i >= size) return false;
        
        bool a = util(nums, set1 + nums[i], i + 1);
        bool b = util(nums, set1, i + 1);
        
        return a || b;
    }
public:
    bool canPartition(vector<int>& nums) {
        size = nums.size();
        sum = accumulate(nums.begin(), nums.end(), 0);
        cout<<sum<<endl;
        if (sum%2 != 0) return false;
        
        return util(nums, 0, 0);
    }
};