class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> cache(size + 1, 0);
        for (int i = 0; i < size; ++i) {
            cache[i + 1] = cache[i] + nums[i];
        }
        int count = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j <= size; ++j) {
                if (cache[j] - cache[i] == k) ++count;
            }
        }
        return count;
    }
};