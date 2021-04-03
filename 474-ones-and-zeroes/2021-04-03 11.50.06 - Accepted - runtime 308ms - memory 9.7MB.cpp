class Solution {
    unordered_map<string,pair<int,int>> cache;
    int _max;
    int size;
    void util(const vector<string> &strs,int m,int n,int i,int count0,int count1,int &run) {
        if (i >= size) {
            return;
        }
        //cout<<"str:"<<strs[i]<<"count0:"<<count0<<"count1:"<<count1<<endl;
        int temp0 = count0+cache[strs[i]].first;
        int temp1 = count1+cache[strs[i]].second;
        if (temp0 <= m && temp1 <= n) {
            _max = max(_max,run+1);
            //cout<<_max<<endl;
            int newrun = run + 1;
            util(strs,m,n,i+1,temp0,temp1,newrun);   
        }
        util(strs,m,n,i+1,count0,count1,run);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> cache(m+1,vector<int>(n+1,0));
        int n0s = 0,n1s = 0;
        
        for(const string &str:strs) {
            n0s = n1s = 0;
            for(char c:str) {
                if (c == '0') {
                    ++n0s;
                } else {
                    ++n1s;
                }
            }
            
            for(int i = m;i >= n0s;--i) {
                for(int j = n;j >= n1s;--j) {
                    cache[i][j] = max(cache[i][j],cache[i-n0s][j-n1s]+1);
                }
            }
        }
        
        return cache[m][n];
    }
};