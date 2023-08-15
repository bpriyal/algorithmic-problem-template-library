class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        int min_ = arrays[0].front();
        int max_ = arrays[0].back();
        int maxDistance = std::numeric_limits<int>::min();

        for (int i = 1; i < m; ++i) {
            maxDistance = max({maxDistance, abs(min_ - arrays[i].back()), abs(max_ - arrays[i].front())});
            min_ = min(min_, arrays[i].front());
            max_ = max(max_, arrays[i].back());
        }

        return maxDistance;
    }
};