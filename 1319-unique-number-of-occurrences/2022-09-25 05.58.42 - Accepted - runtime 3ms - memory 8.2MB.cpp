class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> frequencyCache;
        unordered_set<int> cache;
        
        for (int num : arr) ++frequencyCache[num];
        
        for (auto& it : frequencyCache) {
            if (cache.count(it.second)) return false;
            cache.insert(it.second);
        }
        
        return true;
    }
};