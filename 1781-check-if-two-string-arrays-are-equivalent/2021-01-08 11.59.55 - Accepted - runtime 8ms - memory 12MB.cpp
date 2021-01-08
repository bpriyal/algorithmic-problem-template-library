class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string first = "";
        for(string s:word1) {
            first += s;
        }
        
        string second = "";
        for(string s:word2) {
            second += s;
        }
        
        return first == second;
    }
};