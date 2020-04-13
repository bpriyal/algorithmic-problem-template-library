class Solution {
public:
    unsigned int findMaxLength(vector<int>& nums) {
        int sum;
        unsigned int maxsize=0;
        for (unsigned int i=0;i<nums.size()-1;++i){
            sum = (nums[i]==0) ? -1 : 1;
            for(unsigned int j=i+1;j<nums.size();++j){
                sum+= (nums[j]==0)? -1 : 1;
                if (!sum && maxsize < j-i+1) {
                    maxsize = j-i+1;
                }
            }
        }
        return maxsize;
    }
};