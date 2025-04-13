class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      int size = intervals.size();
      vector<vector<int>> result;

      sort(intervals.begin(), intervals.end(), [](const vector<int>& interval1, const vector<int>& interval2) {
        return interval1[0] < interval2[0];
      });

      int start = intervals[0][0];
      int end = intervals[0][1];

      for (int i = 1; i < size; ++i) {
        if (intervals[i][0] > end) {
          result.emplace_back(vector<int>{start, end});
          start = intervals[i][0];
          end = intervals[i][1];
        } else {
          start = min(start, intervals[i][0]);
          end = max(end, intervals[i][1]);
        }
      }

      result.emplace_back(vector<int>{start, end});

      return result;
    }
};