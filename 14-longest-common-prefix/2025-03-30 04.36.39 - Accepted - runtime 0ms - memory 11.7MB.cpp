class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      int size = strs.size();

      // string prefix = strs[0];

      // for (int i = 1; i < size; ++i) {
      //   int j = 0, k = 0;
      //   string newPrefix;
      //   while (j < prefix.size() && k < strs[i].size() && prefix[j] == strs[i][k]) {
      //     newPrefix.append(1, prefix[j]);
      //     ++j;
      //     ++k;
      //   }
      //   prefix = newPrefix;
      // }
      // return prefix;

      for (int col = 0; col < strs[0].size(); ++col) {
        char c = strs[0][col];
        for (int i = 1; i < size; ++i) {
          if (col == strs[i].size() || c != strs[i][col]) return strs[0].substr(0, col);
        }
      }
      return strs[0];
    }
};