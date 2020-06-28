class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> cache;
        for(int i =0;i<tickets.size();++i) {
            cache[tickets[i][0]].push_back(tickets[i][1]);
        }
        vector<string> result;
        for(auto it=cache.begin();it!=cache.end();++it) {
            sort(begin(it->second),end(it->second));
        }
        string key = "JFK";
        result.push_back("JFK");
        while(true) {
            if (cache[key].size() == 0) break;
            else {
                string temp = cache[key][0];
                result.push_back(temp);
                cache[key].erase(begin(cache[key]));
                key = temp;
            }
        }
        return result;
    }
};