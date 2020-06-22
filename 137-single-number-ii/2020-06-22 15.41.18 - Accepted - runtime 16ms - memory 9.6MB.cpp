class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*unordered_map<int,int> cache;
        for(int i=0;i<nums.size();++i) {
            ++cache[nums[i]];
        }
        for(auto it=cache.begin();it != cache.end();++it) {
            if (it->second == 1) return it->first;
        }
        return 0; */
        
        //solution 2
        int result = 0;
        for (int i =0;i<32;++i) {
            int sum = 0,mask = 1<<i;
            for (int j = 0;j<nums.size();++j) {
                if ((nums[j] & mask) != 0) {
                    ++sum;
                }
            }
            if (sum%3==1) {
                result = (result | mask);
            }
        }
        return result;
    }
};