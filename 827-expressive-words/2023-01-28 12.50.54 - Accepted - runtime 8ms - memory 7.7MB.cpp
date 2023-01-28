class Solution {
    int reachNextChar(char c, int startPos, const string& s) {
        for (int i = startPos + 1; i < s.size(); ++i) {
            if (c != s[i]) return i;
        }

        return s.size();
    }

    bool checkIfLast2EleEqual(int pos, const string& s) {
        int size = s.size();
        if (pos >= size) return false;
        return (pos - 2 >= 0 && pos - 1 >= 0 && s[pos] == s[pos - 2] && s[pos] == s[pos - 1]);
    }

    bool checkIfPrevAndNextEqual(int pos, const string& s) {
        int size = s.size();
        if (pos >= size) return false;
        return (pos - 1 >= 0 && pos + 1 < size && s[pos] == s[pos - 1] && s[pos] == s[pos + 1]);
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
                } else if (checkIfLast2EleEqual(i, s) || checkIfPrevAndNextEqual(i, s)) {
                    i = reachNextChar(s[i], i, s);
                } else break;
            }

            if (checkIfLast2EleEqual(i, s) || checkIfPrevAndNextEqual(i, s)) i = reachNextChar(s[i], i, s);

            if (i == size && j == wordSize) {
                ++result;
            }
        }

        return result;
    }
};