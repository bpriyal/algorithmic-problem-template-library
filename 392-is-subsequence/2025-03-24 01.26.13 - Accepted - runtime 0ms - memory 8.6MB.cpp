class Solution {
public:
    bool isSubsequence(string s, string t) {
      int i = 0, j = 0;
      int sizeS = s.size();
      int sizeT = t.size();

      if (sizeT < sizeS) return false;

      for (int j = 0; j < sizeT; ++j) {
        if (s[i] == t[j]) ++i; 
      }

      return i == sizeS;
    }
};