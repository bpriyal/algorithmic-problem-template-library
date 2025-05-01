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

    unordered_map<string, vector<string>> generateWildCards(const vector<string>& wordList, int L) {
      unordered_map<string, vector<string>> cache;
      for (const auto& word : wordList) {
        for (int i = 0; i < L; ++i) {
          auto pattern = word.substr(0, i) + '*' + word.substr(i + 1, L);
          cache[pattern].emplace_back(word);
        }
      }
      return cache;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      int size = wordList.size();
      queue<string> q;
      q.emplace(beginWord);

      auto cache = generateWildCards(wordList, beginWord.size());

      unordered_set<string> visited;
      int distance = 1;

      while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
          auto currentStr = q.front();
          if (currentStr == endWord) return distance; 
          q.pop();

          for (int j = 0; j < currentStr.size(); ++j) {
            auto pattern = currentStr.substr(0, j) + '*' + currentStr.substr(j + 1);
            for (const auto& word : cache[pattern]) {
              if (!visited.count(word)) {
                q.emplace(word);
                visited.emplace(word);
              }
            }
          }
        }
        ++distance;
      }
      return 0;
    }
};

// O(N*sizeoflargeststring)