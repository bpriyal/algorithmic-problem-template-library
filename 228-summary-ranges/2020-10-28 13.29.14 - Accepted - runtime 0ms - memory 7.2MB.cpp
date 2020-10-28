class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int size = nums.size();
        if(size==0) {
            return {};
        }
        vector<string> result;
        for(int i=0;i<size;i++){
            int temp=nums[i];
            while(i!=(size-1) && nums[i]==nums[i+1]-1)
                ++i;
            int temp1 = nums[i];
            if(temp == temp1)
                result.push_back(to_string(temp));
            else
                result.push_back(to_string(temp) + "->" + to_string(temp1));
        }
        return result;
    }
};