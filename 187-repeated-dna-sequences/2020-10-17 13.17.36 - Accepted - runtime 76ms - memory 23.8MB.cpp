class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.size() < 10) {
            return result;
        }
        unordered_map<string,int> cache;
        for(int i = 0;i<s.size();++i) {
            string str = s.substr(i,10);
            ++cache[str];
            if (cache[str] == 2) {
                result.push_back(str);
            }
        }
        return result;
    }
};