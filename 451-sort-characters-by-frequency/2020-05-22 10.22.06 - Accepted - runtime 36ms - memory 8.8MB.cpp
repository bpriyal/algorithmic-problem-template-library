class Solution {
public:
    
    string frequencySort(string s) {
        unordered_map<char,int> cache;
        vector<pair<char,int>> vec;
        for(auto &ele:s) {
            ++cache[ele];
        }
        for(auto it=cache.begin();it!=cache.end();++it) {
            vec.push_back(make_pair(it->first,it->second));
        }
        sort(vec.begin(),vec.end(),
             [](const pair<char,int> &a,const pair<char,int> &b) {
                 return a.second > b.second;
             });
        string result = "";
        for(auto &ele:vec) {
            int no_of_char = ele.second;
            char c = ele.first;
            while (no_of_char > 0) {
                result += c;
                --no_of_char;
            }
        }
        return result;
    }
};