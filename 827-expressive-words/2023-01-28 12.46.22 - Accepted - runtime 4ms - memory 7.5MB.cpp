class Solution {
    int reachNextChar(char c, int startPos, const string& s) {
        for (int i = startPos + 1; i < s.size(); ++i) {
            if (c != s[i]) return i;
        }

        return s.size();
    }
public:
    int expressiveWords(string s, vector<string>& words) {
        int result = 0;
        int size = s.size();

        for (const auto& word : words) {
            int wordSize = word.size();
            int i = 0, j = 0;

            while (i < size && j < wordSize) {
                if (s[i] == word[j]) {
                    ++i;
                    ++j;
                } else if (i - 2 >= 0 && i - 1 >= 0 && s[i] == s[i - 2] && s[i] == s[i - 1]) {
                    i = reachNextChar(s[i], i, s);
                } else if (i - 1 >= 0 && i + 1 < size && s[i] == s[i - 1] && s[i] == s[i + 1]) {
                    i = reachNextChar(s[i], i, s);
                } else break;
            }

            if (i - 2 >= 0 && i - 1 >= 0 && s[i] == s[i - 2] && s[i] == s[i - 1]) i = reachNextChar(s[i], i, s);
            if (i - 1 >= 0 && i + 1 < size && s[i] == s[i - 1] && s[i] == s[i + 1]) i = reachNextChar(s[i], i, s);

            if (i == size && j == wordSize) {
                ++result;
            }
        }

        return result;
    }
};