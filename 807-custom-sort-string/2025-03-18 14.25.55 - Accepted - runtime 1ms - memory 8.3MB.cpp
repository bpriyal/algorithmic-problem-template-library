class Solution {
public:
    string customSortString(string order, string s) {
      // vector<int> cache(26, 100);
      // for (int i = 0; i < order.size(); ++i) cache[order[i] - 'a'] = i;

      // sort(s.begin(), s.end(), [&cache](char c1, char c2) {
      //   return cache[c1 - 'a'] < cache[c2 - 'a'];
      // });

      // return s;

      unordered_map<char, int> freqMap;
      for (char c : s) ++freqMap[c];

      string result;
      for (char c : order) {
        auto it = freqMap.find(c);
        if (it != freqMap.end()) {
          for (int i = 0; i < it->second; ++i) result += c;
          freqMap.erase(c);
        }
      }

      for (const auto& [c, freq] : freqMap) {
        for (int i = 0; i < freq; ++i) result += c;
      }

      return result;
    }
};