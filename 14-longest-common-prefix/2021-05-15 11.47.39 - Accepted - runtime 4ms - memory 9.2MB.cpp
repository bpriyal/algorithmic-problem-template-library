class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];
        
        for(int i = 1;i < strs.size();++i) {
            //cout<<"1"<<endl;
            int j;
            //cout<<strs[i].size()<<endl;
            for(j = 0;j < result.size() && j < strs[i].size();++j) {
                //cout<<"here"<<endl;
                if (strs[i][j] != result[j]) {
                    break;
                }
            }
            //cout<<j<<","<<result.size()<<endl;
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