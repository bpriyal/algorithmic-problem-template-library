class Solution {
    int size;
    int result;
    void util(string& s, int i, string current) {
        if (i > size || current.size() > 2 || current[0] == '0') {
            return;
        }
        
        if (i == size) {
            ++result;
            return;
        }
        
        if (!current.empty()) util(s, i + 1, current + s[i]);
        util(s, i + 1, string(1, s[i]));
    }
public:
    int numDecodings(string s) {
        size = s.size();
        result = 0;
        
        util(s, 0, "");
        
        return result;
    }
};