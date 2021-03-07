class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(),words.end());
        int result = 0;
        
        for(string word:words) {
            for(int i = 1;i < word.size();++i) {
                s.erase(word.substr(i));
            }
        }
        
        for(string word:s) {
            result += word.size() + 1;
        }
        return result;
    }
};