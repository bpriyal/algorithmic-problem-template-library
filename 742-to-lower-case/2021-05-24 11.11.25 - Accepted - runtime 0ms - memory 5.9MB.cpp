class Solution {
    bool isCap(char c) {
        return c >= 'A' && c <='Z';
    }
public:
    string toLowerCase(string s) {
        int diff = 'a'-'A';
        
        for(char &c:s) {
            if (isCap(c)) {
                c = c + diff;
            }
        }
        
        return s;
    }
};