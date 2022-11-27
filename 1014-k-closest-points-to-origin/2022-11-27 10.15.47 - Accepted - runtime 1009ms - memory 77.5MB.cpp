class Comp {
public:
    bool operator()(const vector<int>& p1, const vector<int>& p2) {
        return (p1[0]*p1[0]) + (p1[1]*p1[1]) < (p2[0]*p2[0]) + (p2[1]*p2[1]);
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Comp> pq;
        vector<vector<int>> result;

        for (auto point : points) {
            pq.emplace(point);

            if (pq.size() > k) pq.pop();
        }

        while (!pq.empty()) {
            result.emplace_back(pq.top()); pq.pop();
        }

        return result;
    }
};