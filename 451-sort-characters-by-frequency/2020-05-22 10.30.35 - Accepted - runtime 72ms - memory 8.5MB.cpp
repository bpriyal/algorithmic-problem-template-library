class Solution {
public:
    
    string frequencySort(string s) {
        //Solution 1
        
        /*unordered_map<char,int> cache;
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
        return result;*/
       
        //solution2 
        /*unordered_map<char,int> cache;
        vector<pair<int,char>> vec;
        for(auto &ele:s) {
            ++cache[ele];
        }
        for(auto it=cache.begin();it!=cache.end();++it) {
            vec.push_back(make_pair(it->second,it->first));
        }
        sort(vec.rbegin(),vec.rend());
        string result = "";
        for(auto &ele:vec) {
            int no_of_char = ele.first;
            char c = ele.second;
            while (no_of_char > 0) {
                result += c;
                --no_of_char;
            }
        }
        return result;*/
        
        //Solution 3
        vector<int> cache(256,0);
        vector<pair<int,char>> vec;
        for(auto &ele:s) {
            ++cache[ele];
        }
        for(int i=0;i<256;++i) {
            if (cache[i]) vec.push_back({cache[i],i});
        }
        sort(vec.rbegin(),vec.rend());
        string result = "";
        for(auto &ele:vec) {
            int no_of_char = ele.first;
            char c = ele.second;
            while (no_of_char > 0) {
                result += c;
                --no_of_char;
            }
        }
        return result;
    }
};