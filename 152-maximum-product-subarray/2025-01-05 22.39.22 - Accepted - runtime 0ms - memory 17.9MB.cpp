class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sum = nums.size();
        int min_so_far = nums[0];
        int max_so_far = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int temp_min_so_far = min({nums[i], nums[i] * min_so_far, nums[i] * max_so_far});
            max_so_far = max({nums[i], nums[i] * min_so_far, nums[i] * max_so_far});
            min_so_far = temp_min_so_far;
            result = max(result, max_so_far);
        }
        return result;
    }
};