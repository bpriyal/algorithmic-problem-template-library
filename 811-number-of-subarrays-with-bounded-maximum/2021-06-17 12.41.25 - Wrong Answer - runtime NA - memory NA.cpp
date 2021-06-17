class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int size = nums.size();
        int result = 0;
        
        for(int i = 0;i < size;++i) {
            int _max = INT_MIN;
            for(int j = i;j < size;++j) {
                _max = max(_max,nums[j]);
                
                if (_max <=right && _max >= left) {
                    //cout<<i<<" "<<j<<endl;
                    ++result;
                } else {
                    break;
                }
            }
        }
        
        return result;
    }
};