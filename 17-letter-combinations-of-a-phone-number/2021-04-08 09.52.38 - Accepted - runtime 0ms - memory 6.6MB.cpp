class Solution {
    vector<string> cache;
    int size;
    vector<string> result;
    void dfs(string digits,int i,string &s) {
        //cout<<i<<endl;
        if (s.size() == size) {
            result.push_back(s);
            return;
        }
        
        for(char c:cache[(digits[i]-'0')-2]) {
            string temp = s+c;
            dfs(digits,i+1,temp);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        size = digits.size();
        if (size == 0) {
            return result;
        }
        cache = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s = {};
        dfs(digits,0,s);
        
        return result;
    }
};