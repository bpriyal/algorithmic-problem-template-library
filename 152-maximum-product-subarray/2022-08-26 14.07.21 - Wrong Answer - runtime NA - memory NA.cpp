class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int result = nums[0];
        
//         int _max = result;
//         int _min = result;
        
//         for(int i = 1; i < size; ++i) {
            
//             if (nums[i] < 0) swap(_min, _max);
            
//             _max = max(_max * nums[i], nums[i]);
//             _min = min(_min * nums[i], nums[i]);
            
//             result = max({_max, _min, result});
//         }
        
        int l = 0;
        int r = 0;
        
        for (int i = 0; i < size; ++i) {
            l = (l? l : 1) * nums[i];
            r = (r? r : 1) * nums[i];
            
            result = max({result, l, r});
        }
        
        return result;
    }
};