class Solution {
    unordered_map<string,vector<pair<string,double>>> cache;
    
    
    double util(string a,string b,double res,unordered_set<string> &s) {
        if (a == b) {
            return res;
        }
        
        for(auto x:cache[a]) {
            if (s.count(x.first) == 0) {
                s.insert(x.first);
                double d = util(x.first,b,x.second*res,s);
                if (d != -1) {
                    return d;
                }
            }
        }
        return -1.0;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int size = values.size();
        for(int i = 0;i < size;++i) {
            cache[equations[i][0]].push_back({equations[i][1],values[i]});
            cache[equations[i][1]].push_back({equations[i][0],static_cast<double>(1/values[i])});
        }
        
        
        vector<double> result;
        for(auto q:queries) {
            if (cache.count(q[0]) == 0 || cache.count(q[1]) == 0) {
                result.push_back(-1.0);
            } else {
                unordered_set<string> s;
                result.push_back(util(q[0],q[1],1.0,s));
            }
        }
        return result;
    }
};