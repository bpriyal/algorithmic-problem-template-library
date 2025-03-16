class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      int size = intervals.size();
      sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
      });

      vector<vector<int>> result;
      int start = intervals[0][0];
      int end = intervals[0][1];
      for (int i = 1; i < size; ++i) {
        if (end >= intervals[i][0]) {
          end = max(end, intervals[i][1]);
        } else {
          result.emplace_back(vector<int>{start, end});
          start = intervals[i][0];
          end = intervals[i][1];
        }
      }
      result.emplace_back(vector<int>{start, end});

      return result;
    }
};