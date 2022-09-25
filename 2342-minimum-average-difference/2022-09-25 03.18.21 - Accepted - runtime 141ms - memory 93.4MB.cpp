class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int size = nums.size();
        vector<long long> prefixSum;
        prefixSum.push_back(0);
        
        pair<int, int> resultIndexPair = std::make_pair(-1, INT_MAX);
        
        for (int i = 0; i < size; ++i) {
            prefixSum.push_back(prefixSum.back() + nums[i]);
        }
        
        for (int i = 0; i < size; ++i) {
            int absDiff = abs((prefixSum[i + 1] / (i + 1)) - ((size - i - 1) > 0? (prefixSum[size] - prefixSum[i + 1])/(size - i - 1) : 0));
            
            if (resultIndexPair.second > absDiff) resultIndexPair = std::make_pair(i, absDiff);
        }

        return resultIndexPair.first;
    }
};