class Solution {
    int size;
    int countPalindromes(const string& s, int l, int r) {
      int count = 0;
      while (l >= 0 && r < size) {
        if (s[l] != s[r]) break;
        ++count;
        --l;
        ++r;
      }
      return count;
    }
public:
    int countSubstrings(string s) {
      size = s.size();
      int count = 0;

      for (int i = 0; i < size; ++i) {
        count += countPalindromes(s, i, i);
        if (i != size - 1) count += countPalindromes(s, i, i + 1);
      }
      return count;
    }
};
// aaa
// aa
// aa