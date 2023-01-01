class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int size = fruits.size();
        int left = 0, right = 0;
        unordered_set<int> cache;
        int result = 0;

        for (right = 0; right < size; ++right) {
            cache.emplace(fruits[right]);
            while (cache.size() > 2) {
                cache.erase(fruits[left]);
                ++left;
            }
            result = max(result, right - left + 1);
        }

        return result;
    }
};