class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size(); // as size of nums1 and nums2 is same
        unordered_map<int, int> cache;
        vector<int> result;
        for (int i = 0; i < size; ++i) cache.emplace(nums2[i], i);
        for (int i = 0; i < size; ++i) result.emplace_back(cache[nums1[i]]);
        return result;
    }
};