class Solution {
    void transformString(string& s) {
        int size = s.size();
        int numberOfHash = 0;
        for (int i = size - 1; i >= 0; --i) {
            if (s[i] == '#') {
                ++numberOfHash;
                continue;
            } else {
                if (numberOfHash) {
                    s[i] = '.';
                    --numberOfHash;
                }
            }
        }
    }
public:
    bool backspaceCompare(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();

        transformString(s);
        transformString(t);

        int i = 0, j = 0;

        while (i < s_size && j < t_size) {
            if (isalpha(s[i]) && isalpha(t[i])) {
                if (s[i] != t[i]) return false;
                ++i;
                ++j;
            } else {
                if (!isalpha(s[i])) {
                    ++i;
                } else {
                    ++j;
                }
            }
        }

        while (i < s_size) {
            if (isalpha(s[i])) return false;
            ++i;
        }

        while (j < t_size) {
            if (isalpha(t[i])) return false;
            ++j;
        }

        return true;
    }
};