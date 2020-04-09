class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>::iterator ptr;
        if(nums.size()==1){ return nums[0];}
        for( ptr=nums.begin();ptr<nums.end()-2;ptr=ptr+2){
            if(*ptr!=*(ptr+1)){
                return *ptr;
            }
        }
        return nums[nums.size()-1];
    }
};
