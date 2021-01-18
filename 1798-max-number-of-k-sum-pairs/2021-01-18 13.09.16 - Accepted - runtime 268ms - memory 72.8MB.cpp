class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> cache;
        for(int num:nums) {
            ++cache[num];
        }
        int result = 0;
        for(int num:nums) {
            if (2*num == k) {
                result += floor(cache[num]/2);
            } else {
                result += min(cache[num],cache[k-num]);
            }
            cache[num] = 0;
        }
        return result;
    }
};