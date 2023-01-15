using replaceTuple = tuple<int, string, string>;
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

        vector<replaceTuple> cache;

        for (int i = 0; i < k; ++i) {
            cache.push_back({indices[i], sources[i], targets[i]});
        }
        cout<<"a"<<endl;

        sort(cache.begin(), cache.end(), [](const replaceTuple& a, const replaceTuple& b) {
            cout<<"eh"<<endl;
            return get<0>(a) < get<0>(b);
        });
        cout<<"here"<<endl;
        string result = s;

        for (int i = k - 1; i >= 0; --i) {
            cout<<i<<endl;
            if (get<1>(cache[i]) == s.substr(get<0>(cache[i]), get<1>(cache[i]).size())) {
                replace(result, get<0>(cache[i]), get<1>(cache[i]).size(), get<2>(cache[i]));
            }
        }

        return result;
    }
};