class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product;
        if (nums.size()==0){
            product.push_back(0);
            return product;
        };
        int left[nums.size()];
        int right[nums.size()];
        
        
        int i;
        left[0] = 1;
        right[nums.size()-1] = 1;
        
        for (i=1;i<nums.size();i++){
            left[i] = left[i-1] * nums[i-1];
        }
        
        for (i=nums.size()-2;i>=0;--i){
            right[i] =right[i+1] * nums[i+1];
        }
        
        for(i=0;i<nums.size();i++){
            product.push_back(left[i]*right[i]);
        }
        return product;
    }
};