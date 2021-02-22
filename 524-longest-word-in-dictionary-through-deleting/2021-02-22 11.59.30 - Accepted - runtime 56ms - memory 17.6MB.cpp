class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string result;
        int maxSize = 0;
        int ssize = s.size();
        
        for(string word:d) {
            int size = word.size();
            if (size >= maxSize) {
                int idx = 0;
                for(int i = 0;i < ssize;++i) {
                    if (s[i] == word[idx]) {
                        ++idx;
                    }
                    if (idx == size) {
                        break;
                    }
                }
                if (idx == size) {
                    if (size == maxSize) {
                        if (result > word) {
                            result = word;
                        }
                    } else {
                        maxSize = size;
                        result = word;
                    }
                }
            }
        }
        return result;
    }
};