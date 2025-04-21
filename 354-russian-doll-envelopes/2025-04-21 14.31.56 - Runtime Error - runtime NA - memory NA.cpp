class Solution {
    int binarySearch(const vector<vector<int>>& envelopes, const vector<int>& target) {
      int size = envelopes.size();
      int left = 0, right = size - 1;

      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (envelopes[mid][1] >= target[1]) right = mid - 1;
        else left = right + 1;
      }
      return left;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      int size = envelopes.size();
      vector<vector<int>> sub;
      sort(envelopes.begin(), envelopes.end(), [](const vector<int>& v1, const vector<int>& v2) {
        if (v1[0] == v2[0]) return v1[1] > v2[1];
        return v1[0] < v2[0];
      });
      sub.emplace_back(envelopes[0]);

      for (int i = 1; i < size; ++i) {
        if (envelopes[i][1] > sub.back()[1]) {
          sub.emplace_back(envelopes[i]);
        } else {
          auto idx = binarySearch(envelopes, envelopes[i]);
          sub[idx] = envelopes[i];
        }
      }
      return sub.size();
    }
};

// [[5,4],[6,4],[6,7],[2,3]]

// 1 1 2 2 3 3

