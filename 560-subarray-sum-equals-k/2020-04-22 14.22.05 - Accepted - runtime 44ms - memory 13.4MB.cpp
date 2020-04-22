class Solution {
public:
    int subarraySum(vector<int>& nums,long int k) {
        if (nums.size() == 0) return 0;
        int count=0;
        long int sum=0;
        unordered_map<long int,int> freq;
        for (auto x : nums) {
            sum = sum + x;
            if (sum == k) ++count;
            if (freq.find(sum - k) != freq.end()) {
                count = count + freq[sum - k];
            }
            freq[sum]++;
        }
        return count;
    }
};