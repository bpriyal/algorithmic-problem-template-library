class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> cache1(nums1.begin(), nums1.end());
        unordered_set<int> cache2(nums2.begin(), nums2.end());
        
        vector<int> result;
        
        for (auto it = cache1.begin(); it != cache1.end(); ++it) {
            if (cache2.count(*it)) result.push_back(*it);
        }
        
        return result;
    }
};