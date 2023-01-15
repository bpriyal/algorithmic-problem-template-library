class Solution {
    void replace(string& s, int index, int numberOfChar, const string& replacement) {
        string prefix = s.substr(0, index);
        string suffix = s.substr(index + numberOfChar);
        cout<<"prefix: "<<prefix<<", suffix: "<<suffix<<endl;
        s = prefix + replacement + suffix;
    }
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int size = s.size();
        int k = indices.size();
        string result = s;

        for (int i = k - 1; i >= 0; --i) {
            cout<<i<<endl;
            if (sources[i] == s.substr(indices[i], sources[i].size())) {
                replace(result, indices[i], sources[i].size(), targets[i]);
            }
        }

        return result;
    }
};