class Solution {
    int dist(const vector<int>& point) {
      return point[0] * point[0] + point[1] * point[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      int size = points.size();
      // priority_queue<pair<int, int>> pq;

      // for (int i = 0; i < size; ++i) {
      //   pair<int, int> p = { dist(points[i]), i } ;
      //   if (pq.size() == k) {
      //     if (p.first < pq.top().first) {
      //       pq.pop();
      //       pq.emplace(p);
      //     }
      //   } else {
      //     pq.emplace(p);
      //   }
      // }

      // vector<vector<int>> result;
      // while (!pq.empty()) {
      //   result.emplace_back(points[pq.top().second]);
      //   pq.pop();
      // }
      // return result;

      if (size == k) return points;
      int left = 0;
      int right = size - 1;

      while (left <= right) {
        cout << "left: " << left << ", right: " << right << endl;
        int pivotIdx = left + rand() % (right - left + 1);

        // swap pivot with last index
        swap(points[pivotIdx], points[right]);

        int infPoint = left;
        int pivotDist = dist(points[right]);
        cout << points[right][0] << points[right][1] << endl;
        cout << "pivotDist: " << pivotDist << endl;
        for (int i = left; i <= right; ++i) {
          if (dist(points[i]) < pivotDist) {
            swap(points[infPoint], points[i]);
            ++infPoint;
          }
        }
        swap(points[infPoint], points[right]);
        cout << "infPoint: " << infPoint << endl;
        if (infPoint == k) return vector<vector<int>>(points.begin(), points.begin() + k);
        else if (infPoint > k) right = infPoint - 1;
        else left = infPoint + 1;
      }

      return vector<vector<int>>();
    }
};