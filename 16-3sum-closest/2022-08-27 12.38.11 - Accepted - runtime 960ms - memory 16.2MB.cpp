class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int result = nums[0] + nums[1] + nums[2];
        
        for(int i = 0; i < size - 1; ++i) {
            int newTarget = target - nums[i];
            
            int l = i + 1;
            int r = size - 1;
            
            while (l < r) {
                int sum = nums[l] + nums[r];
                
                if (abs(sum + nums[i] - target) < abs(result - target)) {
                    cout<<"l:"<<nums[l]<<", r:"<<nums[r]<<", i: "<<nums[i]<<endl;
                    result = sum + nums[i];
                }
                
                if (sum == newTarget) {
                    return target;
                } else if (sum > newTarget) {
                    --r;
                } else {
                    ++l;
                }
            }
        }
        
        return result;
    }
};