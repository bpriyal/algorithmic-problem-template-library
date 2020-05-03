class Solution {
public:
    map<string,int> pair;
    string destCity(vector<vector<string>>& paths) {
        int row = paths.size();
        for (auto x : paths) {
            pair[x[0]] = 1;
            pair[x[1]] = 0;
        }
        for (auto x:pair) {
            if (x.second == 0) {
                cout<<x.first<<endl;
                return x.first;
            }
        }
        return "";
    }
};