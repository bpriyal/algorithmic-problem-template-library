class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
      auto comp = [](const vector<int>& v1, const vector<int>& v2) -> bool { return v1[0] < v2[0]; };
      sort(slots1.begin(), slots1.end(), comp);
      sort(slots2.begin(), slots2.end(), comp);

      int i = 0, j = 0;
      while (i < slots1.size() && j < slots2.size()) {
        int start = max(slots1[i][0], slots2[j][0]);
        int end = min(slots1[i][1], slots2[j][1]);
        if (start <= end) { // there is an overlap
          if (end - start >= duration) return vector<int>{start, start + duration};
        }
        slots1[i][1] >= slots2[j][1] ? ++j : ++i;
      }
      return {};
    }
};