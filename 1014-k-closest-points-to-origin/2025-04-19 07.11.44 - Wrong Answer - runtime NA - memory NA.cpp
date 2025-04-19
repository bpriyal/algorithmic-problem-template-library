class Solution {
    int distance(const vector<int>& point) { return point[0] * point[0] + point[1] * point[1]; }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      int size = points.size();
      // priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

      // for (int i = 0; i < size; ++i) {
      //   int currDistance = distance(points[i]);
      //   if (pq.size() < k) {
      //     pq.emplace(currDistance, i);
      //   } else {
      //     if (pq.top().first > currDistance) {
      //       pq.pop();
      //       pq.emplace(currDistance, i);
      //     }
      //   }
      // }

      // vector<vector<int>> result;
      // while (!pq.empty()) {
      //   result.emplace_back(points[pq.top().second]);
      //   pq.pop();
      // }
      // return result;

      // Quick select
      int left = 0, right = size - 1;
      while (left <= right) {
        int pivot = left + (rand() % (right - left + 1));
        swap(points[pivot], points[right]);
        int inflectionPoint = left;
        for (int i = left; i < right; ++i) {
          if (distance(points[i]) <= distance(points[right])) {
            swap(points[inflectionPoint], points[i]);
            ++inflectionPoint;
          }
        }
        swap(points[inflectionPoint], points[right]);
        for (int i = 0; i < size; ++i) cout << "x: " << points[i][0] << ", y: " << points[i][1] << "\t";
        cout << endl << "inflectionPoint: " << inflectionPoint << endl;
        if (inflectionPoint == k) return vector<vector<int>>{points.begin(), points.begin() + k};
        else if (inflectionPoint < k) left = inflectionPoint + 1;
        else right = inflectionPoint - 1;
      }
      return {};
    }
};