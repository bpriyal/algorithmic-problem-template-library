class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int size = nums.size();
        vector<int> cache(size);
        vector<int> result(2);
        for(int num:nums) {
            ++cache[num-1];
            if (cache[num-1] > 1) {
                result[0] = num;
                break;
            }
        }
        
        for(int i = 0;i < size;++i) {
            if (cache[i] == 0) {
                result[1] = i+1;
                break;
            }
        }
        return result;
    }
};