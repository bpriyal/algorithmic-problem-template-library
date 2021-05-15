class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];
        
        for(int i = 1;i < strs.size();++i) {
            int j;
            for(j = 0;j < result.size() && j < strs[i].size();++j) {
                if (strs[i][j] != result[j]) {
                    break;
                }
            }
            int x = result.size();
            while (j < x && result != "") {
                result.pop_back();
                ++j;
            }
            
            if (result == "") {
                return "";
            }
        }
        
        return result;
    }
};