class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int size = nums.size();
        vector<int> cache(size + 1, 0);
        
        for (int num : nums) {
            ++cache[num];
        }
        
        vector<int> result(2);
        
        for (int i = 1; i <= size; ++i) {
            if (cache[i] == 2) result[0] = i;
            else if (cache[i] == 0) result[1] = i;
        }
        
        return result;
    }
};