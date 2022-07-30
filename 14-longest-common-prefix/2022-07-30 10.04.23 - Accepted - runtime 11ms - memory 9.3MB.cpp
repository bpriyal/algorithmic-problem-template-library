class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int i = 0;
        int numberStrings = strs.size();
        
        while(true) {
            char c = '\0';
            
            for(int j = 0;j < numberStrings; ++j) {
                if (strs[j].size() <= i) return result;
                if (c == '\0') c = strs[j][i];
                if (c != strs[j][i]) return result;
            }
            
            result += c;
            ++i;
        }
        
        return result;
    }
};