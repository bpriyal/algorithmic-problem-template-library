class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        long long result = 0;
        
//         for (int right = 0; right < size; ++right) {
//             if (nums[right]) left = right;
            
//             while (right >= left && nums[left]) {
//                 ++left;
//             }
            
//             if (right >= left) result += right - left + 1;
//         }
        
        for (int right = 0; right < size; ++right) {
            if (nums[right]) left = right + 1;
            
            result += right - left + 1;
        }
        
        return result;
    }
};