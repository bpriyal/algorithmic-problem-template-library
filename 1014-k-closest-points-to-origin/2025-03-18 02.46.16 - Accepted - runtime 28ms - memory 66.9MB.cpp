class Solution {
    int dist(const vector<int>& point) {
      return point[0] * point[0] + point[1] * point[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      int size = points.size();
      priority_queue<pair<int, int>> pq;

      for (int i = 0; i < size; ++i) {
        pair<int, int> p = { dist(points[i]), i } ;
        if (pq.size() == k) {
          if (p.first < pq.top().first) {
            pq.pop();
            pq.emplace(p);
          }
        } else {
          pq.emplace(p);
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