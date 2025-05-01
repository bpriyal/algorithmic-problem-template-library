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
        // cout << "q.size: " << q.size() << endl;
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
          auto currentStr = q.front();
          // cout << currentStr << endl;
          if (currentStr == endWord) return distance; 
          q.pop();

          for (int j = 0; j < size; ++j) {
            if (!visited[j] && canUse(currentStr, wordList[j])) {
              q.emplace(wordList[j]);
              visited[j] = true;
            }
          }
        }
        ++distance;
      }
      return 0;
    }
};