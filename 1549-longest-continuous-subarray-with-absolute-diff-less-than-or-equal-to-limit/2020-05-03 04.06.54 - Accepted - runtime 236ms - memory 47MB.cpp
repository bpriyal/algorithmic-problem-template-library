class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> con;
        int j(0), res(0);
        int i,size = nums.size();
        for (i=0;i<size;++i) {
            con.insert(nums[i]);
            while(*con.rbegin() - *con.begin() > limit) {
                con.erase(con.find(nums[j++]));
            }
            res = max(res,i-j+1);
        }
        return res;
    }
};