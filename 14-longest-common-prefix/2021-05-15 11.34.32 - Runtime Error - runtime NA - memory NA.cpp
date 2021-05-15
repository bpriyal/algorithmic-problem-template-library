class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];
        
        for(int i = 1;i < strs.size();++i) {
            int j;
            for(j = 0;j < result.size();++j) {
                if (strs[i][j] != result[j]) {
                    break;
                }
            }
            while (j <= result.size()) {
                result.pop_back();
                ++j;
            }
            //cout<<result<<endl;
        }
        
        return result;
    }
};