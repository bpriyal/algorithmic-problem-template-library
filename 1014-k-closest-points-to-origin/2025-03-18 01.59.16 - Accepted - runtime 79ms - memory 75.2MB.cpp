class Solution {
    int dist(const vector<int>& point) {
      return point[0] * point[0] + point[1] * point[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      int size = points.size();

      auto comp = [this](const vector<int>& p1, const vector<int>& p2) {
        return dist(p1) < dist(p2);
      };
      priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

      for (const auto& point : points) {
        if (pq.size() == k) {
          if (dist(point) < dist(pq.top())) {
            pq.pop();
            pq.emplace(point);
          }
        } else {
          pq.emplace(point);
        }
      }

      vector<vector<int>> result;
      while (!pq.empty()) {
        result.emplace_back(pq.top());
        pq.pop();
      }
      return result;
    }
};