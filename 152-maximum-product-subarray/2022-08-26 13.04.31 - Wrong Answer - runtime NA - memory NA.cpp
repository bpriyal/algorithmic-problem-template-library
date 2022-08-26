class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int result = nums[0];
        
        int _max = result;
        int _min = result;
        
        for(int i = 1; i < size; ++i) {
            _max = max(_max * nums[i], nums[i]);
            _min = min(_min * nums[i], nums[i]);
            
            result = max({_max, _min, result});
            cout<<i<<","<<result<<endl;
        }
        
        return result;
    }
};