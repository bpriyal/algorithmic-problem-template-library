class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cache(nums.begin(), nums.end());
        int longestSequence = -1;
        for (const auto& num : nums) {
            if (!cache.count(num - 1)) {
                int current = num;
                int sequence = 1;
                while (cache.count(current + 1)) {
                    ++sequence;
                    ++current;
                }
                longestSequence = max(longestSequence, sequence);
            }
        }
        return longestSequence;
    }
};