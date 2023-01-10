class Solution {
    inline string getConcatenatedString(int num1, int num2) {
        return to_string(num1) + "->" + to_string(num2); 
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int size = nums.size();
        vector<string> result;
        if (!size) {
            if (lower == upper) result.emplace_back(to_string(lower));
            else result.emplace_back(getConcatenatedString(lower, upper));
            return result;
        }

        // first range
        int initialDiff = nums.front() - lower;
        if (initialDiff > 1) {
            result.emplace_back(getConcatenatedString(lower, nums.front() - 1));
        }

        // middle range from array
        for (int i = 0; i < size - 1; ++i) {
            int consecutiveDiff = nums[i + 1] - nums[i];
            if (consecutiveDiff > 1) {
                result.emplace_back(consecutiveDiff > 2? getConcatenatedString(nums[i] + 1, nums[i + 1] - 1) : to_string(nums[i] + 1));
            }
        }

        // upper range
        int upperDiff = upper - nums.back();
        if (upperDiff > 1) {
            result.emplace_back(getConcatenatedString(nums.back() + 1, upper));
        }

        return result;
    }
};