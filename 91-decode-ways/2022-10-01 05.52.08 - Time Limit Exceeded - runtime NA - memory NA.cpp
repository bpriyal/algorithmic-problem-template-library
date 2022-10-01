class Solution {
    int size;
    int result;
    vector<int> dp;
    int util(string& s, int i, string current) {
        //cout<<current<<endl;
        if (!current.empty() && (i > size || current.size() > 2 || current[0] == '0' || stoi(current) > 26)) {
            return 0;
        }
        
        if (i == size) {
            return 1;
        }
        
        return (current.empty() ? 0 : util(s, i + 1, current + s[i])) + util(s, i + 1, string(1, s[i]));
    }
public:
    int numDecodings(string s) {
        size = s.size();
        result = 0;
        dp.resize(size, -1);
        return util(s, 0, "");
        
        return result;
    }
};