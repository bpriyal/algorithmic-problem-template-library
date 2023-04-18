class Solution {
    bool pointsShareXorYAxis(const vector<int>& point1, const vector<int>& point2) {
        return point1[0] == point2[0] || point1[1] == point2[1];
    }
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> cache;
        int minimumArea = INT_MAX;

        for (const auto& point : points) cache[point[0]].emplace(point[1]);

        for (const auto& point1 : points) {
            for (const auto& point2 : points) {
                if (pointsShareXorYAxis(point1, point2)) continue;
                if (cache[point1[0]].count(point2[1]) && cache[point2[0]].count(point1[1])) {
                    minimumArea = min(minimumArea, abs(point1[0] - point2[0]) * abs(point1[1] - point2[1]));
                }
            }
        }
        return minimumArea == INT_MAX? 0 : minimumArea;
    }
};