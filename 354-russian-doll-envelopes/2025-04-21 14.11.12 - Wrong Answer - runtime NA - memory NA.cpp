class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      int size = envelopes.size();
      vector<vector<int>> sub;
      sort(envelopes.begin(), envelopes.end());
      sub.emplace_back(envelopes[0]);

      for (int i = 1; i < size; ++i) {
        if (envelopes[i][0] > sub.back()[0] && envelopes[i][1] > sub.back()[1]) {
          sub.emplace_back(envelopes[i]);
        } else {
          auto it = std::lower_bound(sub.begin(), sub.end(), envelopes[i]);
          if (it != sub.end()) *it = envelopes[i];
        }
      }
      return sub.size();
    }
};

// [[5,4],[6,4],[6,7],[2,3]]

