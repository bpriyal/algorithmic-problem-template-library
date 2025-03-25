class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
      int size1 = firstList.size();
      int size2 = secondList.size();
      int i = 0, j = 0;

      vector<vector<int>> result;
      while (i < size1 && j < size2) {
        const auto& interval1 = firstList[i];
        const auto& interval2 = secondList[j];

        if (interval1[1] < interval2[0]) ++i;
        else if (interval2[1] < interval1[0]) ++j;
        else { // intersection
          int start = max(interval1[0], interval2[0]);
          int end = min(interval1[1], interval2[1]);
          result.emplace_back(vector<int>({start, end}));
          if (end == interval1[1]) ++i;
          else ++j;
        }
      }

      return result;
    }
};