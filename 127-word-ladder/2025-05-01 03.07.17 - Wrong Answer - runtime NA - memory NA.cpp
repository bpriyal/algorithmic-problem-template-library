class Solution {
    bool canUse(const string& str1, const string& str2) {
      bool diffCount = false;
      if (str1.size() != str2.size()) return false;
      for (int i = 0; i < str1.size(); ++i) {
        if (str1[i] != str2[i]) {
          if (diffCount) return false;
          diffCount = true;
        }
      }
      return true;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      int size = wordList.size();
      queue<string> q;
      q.emplace(beginWord);
      vector<bool> visited(size, false);
      int distance = 1;

      while (!q.empty()) {
        for (int i = 0; i < q.size(); ++i) {
          auto currentStr = q.front();
          if (currentStr == endWord) return distance; 
          q.pop();

          for (int i = 0; i < size; ++i) {
            if (!visited[i] && canUse(currentStr, wordList[i])) {
              q.emplace(wordList[i]);
              visited[i] = true;
            }
          }
        }
        ++distance;
      }
      return 0;
    }
};