class Solution {
    int binarySearch(const vector<vector<int>>& sub, const vector<int>& target) {
      int size = sub.size();
      int left = 0, right = size - 1;
      for (auto& num : sub) cout << "[" << num[0] << "," << num[1] << "]\t";
      cout << endl;

      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sub[mid][1] >= target[1]) right = mid - 1;
        else left = mid + 1;
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

      for (auto& num : envelopes) cout << "[" << num[0] << "," << num[1] << "]\t";
      cout << endl;
      sub.emplace_back(envelopes[0]);

      for (int i = 1; i < size; ++i) {
        cout << "i: " << i <<endl;
        if (envelopes[i][1] > sub.back()[1]) {
          cout << "adding" << endl;
          sub.emplace_back(envelopes[i]);
        } else {
          auto idx = binarySearch(sub, envelopes[i]);
          cout << "Swapping at idx: " << idx << endl;
          sub[idx] = envelopes[i];
        }
      }
      return sub.size();
    }
};

// [[5,4],[6,4],[6,7],[2,3]]

// 1 1 2 2 3 3

// [1,1] [2,3] [4,6]