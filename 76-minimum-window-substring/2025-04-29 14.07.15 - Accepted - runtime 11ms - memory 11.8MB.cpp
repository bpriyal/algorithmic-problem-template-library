class Solution {
public:
    string minWindow(string s, string t) {
      unordered_map<char, int> tCharToFreqMap;
      for (const auto& c : t) ++tCharToFreqMap[c];

      int left = 0, right = 0;
      int formed = 0; // no of unique characters with correct frequency in current window
      int required = tCharToFreqMap.size();

      unordered_map<char, int> windowCharToFreqMap;
      vector<int> result = {-1, 0, 0};

      while (right < s.size()) {
        char c = s[right];
        ++windowCharToFreqMap[c];
        if (auto it = tCharToFreqMap.find(c); it != tCharToFreqMap.end() && it->second == windowCharToFreqMap[c])
          ++formed;

        while (left <= right && formed == required) {
          if (result[0] == -1 || right - left + 1 < result[0]) {
            result[0] = right - left + 1; result[1] = left; result[2] = right;
          }
          c = s[left];
          --windowCharToFreqMap[c];
          if (auto it = tCharToFreqMap.find(c); it != tCharToFreqMap.end() && it->second > windowCharToFreqMap[c])
            --formed;
          ++left;
        }
        ++right;
      }
      return result[0] == -1 ? "" : s.substr(result[1], result[2] - result[1] + 1);
    }
};