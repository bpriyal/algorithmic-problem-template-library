class Solution {
public:
    string customSortString(string order, string s) {
      vector<int> cache(26, 100);
      for (int i = 0; i < order.size(); ++i) cache[order[i] - 'a'] = i;

      sort(s.begin(), s.end(), [&cache](char c1, char c2) {
        return cache[c1 - 'a'] < cache[c2 - 'a'];
      });

      return s;
    }
};