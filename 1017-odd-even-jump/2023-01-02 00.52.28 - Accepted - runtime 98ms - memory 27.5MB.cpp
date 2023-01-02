class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int size = arr.size();
        vector<int> higher(size); vector<int> lower(size);
        int result = 1;
        higher[size - 1] = lower[size - 1] = 1;
        map<int, int> cache;
        cache[arr[size - 1]] = size - 1;

        for (int i = size - 2; i >= 0; --i) {
            auto hi = cache.lower_bound(arr[i]);
            auto lo = cache.upper_bound(arr[i]);

            if (hi != cache.end()) higher[i] = lower[hi->second];
            if (lo != cache.begin()) lower[i] = higher[(--lo)->second];
            if (higher[i]) ++result;
            cache[arr[i]] = i;
        }

        return result;
    }
};