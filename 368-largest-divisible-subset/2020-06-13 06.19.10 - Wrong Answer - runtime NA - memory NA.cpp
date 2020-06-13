class Solution {
public:
    vector<int> vec1;
    vector<int> vec2;
    vector<int> util(const vector<int> &nums,int mult,int i,const vector<int> &curr) {
        if (i>=nums.size()) return curr;
        if (mult%nums[i] ==0 || nums[i]%mult == 0) {
            vec1 = curr;
            vec2 = curr;
            if(!std::binary_search(vec1.begin(),vec1.end(),nums[i])) {
                vec1.push_back(nums[i]);
            }
            util(nums,mult*nums[i],i+1,vec1);
            util(nums,mult,i+1,vec2);
            return vec1.size() > vec2.size()? vec1:vec2;
        }
        return util(nums,mult,i+1,curr);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> curr;
        return util(nums,1,0,curr);
    }
};