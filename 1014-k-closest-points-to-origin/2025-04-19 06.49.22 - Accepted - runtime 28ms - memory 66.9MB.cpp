class Solution {
    int distance(const vector<int>& point) { return point[0] * point[0] + point[1] * point[1]; }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      int size = points.size();
      priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

      for (int i = 0; i < size; ++i) {
        int currDistance = distance(points[i]);
        if (pq.size() < k) {
          pq.emplace(currDistance, i);
        } else {
          if (pq.top().first > currDistance) {
            pq.pop();
            pq.emplace(currDistance, i);
          }
        }
      }

      vector<vector<int>> result;
      while (!pq.empty()) {
        result.emplace_back(points[pq.top().second]);
        pq.pop();
      }
      return result;
    }
};