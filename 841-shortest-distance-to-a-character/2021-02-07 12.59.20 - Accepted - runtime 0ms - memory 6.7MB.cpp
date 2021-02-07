class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int size = s.size();
        vector<int> result(size);
        int pos = -size;
        
        for(int i = 0;i < size;++i) {
            if (s[i] == c) {
                pos = i;
            }
            result[i] = i - pos;
        }
        
        for(int i = pos - 1;i >= 0;--i) {
            if (s[i] == c) {
                pos = i;
            }
            result[i] = min(result[i],pos - i);
        }
        return result;
    }
};