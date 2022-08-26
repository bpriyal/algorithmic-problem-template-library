class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int result = nums[0];
        
        for(int i = 0; i < size; ++i) {
            int mult = nums[i];
            for(int j = i + 1; j < size; ++j) {
                mult *= nums[j];
                result = max(result, mult);
                
                // cout<<"i: "<<nums[i]<<", j:"<<nums[j]<<", result = "<<result<<endl;
            }
        }
        
        return result;
    }
};