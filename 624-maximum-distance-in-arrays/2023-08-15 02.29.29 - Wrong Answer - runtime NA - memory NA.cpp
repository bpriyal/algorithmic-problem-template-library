class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        sort(arrays.begin(), arrays.end(), [](const auto& array1, const auto& array2) {
            return array1[0] < array2[0];
        });
        int maxEnd = std::numeric_limits<int>::min();
        for (int i = 1; i < m; ++i) {
            maxEnd = max(maxEnd, arrays[i].back());
        }

        return abs(maxEnd - arrays[0].front());
    }
};