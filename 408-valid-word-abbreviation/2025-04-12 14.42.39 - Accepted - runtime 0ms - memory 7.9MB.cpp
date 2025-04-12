class Solution {
    int wordSize, abbrSize;
    int extractNum(const string& abbr, int& j) {
      int num = 0;
      while (j < abbrSize && isdigit(abbr[j])) {
        num = num * 10 + (abbr[j] - '0');
        ++j;
      }
      return num;
    }
public:
    bool validWordAbbreviation(string word, string abbr) {
      wordSize = word.size();
      abbrSize= abbr.size();

      int i = 0, j = 0;

      while (j < abbrSize && i < wordSize) {
        if (isalpha(abbr[j])) {
          if (abbr[j] != word[i]) {
            return false;
          }
          ++i;
          ++j;
        } else {
          if (abbr[j] == '0') return false;
          auto num = extractNum(abbr, j);
          i += num;
        }
      }

      return i == wordSize && j == abbrSize;
    }
};