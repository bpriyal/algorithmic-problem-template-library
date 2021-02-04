class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int result = 0;
        for(int i = 1, start = 0, new_start = 0; i<nums.size(); i++)
        {

            if (nums[i] - nums[start] > 1)    
                start = new_start;
            if (nums[i] != nums[i-1]) 
                new_start = i;
            if(nums[i] - nums[start] == 1)
                result = max(result, i-start+1);
        }
        return result;
    }
};