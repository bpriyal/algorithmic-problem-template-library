class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> product;
        for(int i=0;i<size;i++) {
            product.push_back(1);
        }
        int temp=1;
        for(int i=1;i<size;i++){
            product[i] = temp;
            temp*= nums[i];
        }
        temp=1;
        for(int i=size-1;i>=0;--i){
            product[i] =temp*product[i];
            temp*= nums[i];
        }
        return product;
        
    }
};