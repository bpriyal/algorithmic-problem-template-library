class Solution {
    unordered_map<string,vector<string>> dp;
    int size;
    vector<string> util(string s,const vector<string>& wordDict) {
        if (s.size() == 0) {
            return {""};
        }
        if (dp.find(s) != dp.end()) {
            return dp[s];
        }
        vector<string> partial,result;
        for(auto &word:wordDict) {
            string subStr = s.substr(0,word.size());
            if (subStr != word) {
                continue;
            } else {
                //cout<<"whatabouthere"<<endl;
                partial = util(s.substr(word.size()),wordDict);
            }
            
            for(auto &part:partial) {
                //cout<<"jere"<<endl;
                //cout<<part<<endl;
                if (part.size() == 0) {
                    result.push_back(word);
                } else {
                    result.push_back(word+" "+part);
                }
            }
        }
        return dp[s] = result;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        size = wordDict.size();
        return util(s,wordDict);
    }
};