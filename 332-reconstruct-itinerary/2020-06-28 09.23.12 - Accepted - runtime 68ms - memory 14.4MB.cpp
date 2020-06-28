class Solution {
    unordered_map<string,vector<string>> cache;
    vector<string> result;
    int size;
    int dfs(string key) {
        if (result.size() == size + 1) return 1;
        if (cache[key].size() == 0) return -1;
        for(int i = 0;i<cache[key].size();++i) {
            string temp = cache[key][i];
            if (cache[key][i] == "") {
                //cout<<"****"<<endl;
                continue;
            }
            result.push_back(cache[key][i]);
            cache[key][i] = "";
            int res = dfs(temp);
            //cout<<res<<endl;
            if (res == 1) return 1;
            if (res == -1) {
                result.pop_back();
                cache[key][i] = temp;
            }
        }
        return -1;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        size = tickets.size();
        for(int i =0;i<tickets.size();++i) {
            cache[tickets[i][0]].push_back(tickets[i][1]);
        }
        for(auto it=cache.begin();it!=cache.end();++it) {
            sort(begin(it->second),end(it->second));
        }
        string key = "JFK";
        result.push_back("JFK");
        dfs(key);
        return result;
    }
};