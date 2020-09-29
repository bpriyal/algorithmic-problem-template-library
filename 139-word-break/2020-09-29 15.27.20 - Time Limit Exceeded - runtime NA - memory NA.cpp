class Solution {
    int size;
    bool util(string s,const unordered_map<string,int> &cache,int pos) {
        //cout<<s<<endl;
        //cout<<pos<<endl;
        if (pos == s.size()) {
            return s.size()==0? true:false;
        }
        string temp = s.substr(0,pos+1);
        std::size_t n = s.find(temp);
        //printf("%s||%d\n",temp.c_str(),n);
        if (cache.find(temp) != cache.end()) {
            //cout<<"**"<<endl;
            //cout<<s.substr(n+temp.size())<<endl;
            return util(s.substr(n+temp.size()),cache,0) || util(s,cache,pos+1);
        } 
        return util(s,cache,pos+1);
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        size = s.size();
        unordered_map<string,int> cache;
        for(auto word:wordDict) {
            ++cache[word];
        }
        return util(s,cache,0);
    }
};