class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2,0);
        int xy;
        for(auto &x:nums) {
            xy ^= x;
        }
        int d = xy;
        d &= -d;
        for(auto &num:nums) {
            if ((num&d) == 0) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }
        return result;
    }
};