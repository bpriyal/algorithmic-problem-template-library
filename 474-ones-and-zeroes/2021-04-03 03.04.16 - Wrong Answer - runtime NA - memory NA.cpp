class Solution {
    unordered_map<string,pair<int,int>> cache;
    int _max;
    int size;
    void util(const vector<string> &strs,int m,int n,int i,int &count0,int &count1,int run) {
        if (i >= size) {
            return;
        }
        int temp0 = count0+cache[strs[i]].first;
        int temp1 = count1+cache[strs[i]].second;
        if (temp0 <= m && temp1 <= n) {
            _max = max(_max,run+1);
            cout<<_max<<endl;
            util(strs,m,n,i+1,temp0,temp1,run+1);   
        }
        util(strs,m,n,i+1,count0,count1,run);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        size = strs.size();
        _max = 0;
        for(const string &str:strs) {
            int n0s = 0;
            int n1s = 0;
            for(char c:str) {
                if (c == '0') {
                    ++n0s;
                } else {
                    ++n1s;
                }
            }
            cache[str] = {n0s,n1s};
        }
        int count0 = 0;
        int count1 = 1;
        util(strs,m,n,0,count0,count1,0);
        return _max+1;
    }
};