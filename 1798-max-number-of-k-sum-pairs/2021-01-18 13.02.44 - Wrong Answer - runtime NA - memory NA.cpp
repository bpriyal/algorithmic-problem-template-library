class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> cache;
        for(int num:nums) {
            ++cache[num];
        }
        int result = 0;
        set<int> s(nums.begin(),nums.end());
        for(int num:s) {
            if (num == k/2) {
                result += floor(cache[num]/2);
            } else {
                result += min(cache[num],cache[k-num]);
            }
        }
        return result;
    }
};