class Solution {
public:
    list<char> li;
    unordered_map<char,list<char>::iterator> cache;
    void add_ele(char c) {
        li.push_back(c);
        auto it = li.end();
        --it;
        cache[c] = it;
    }
    void remove_ele(char c) {
        li.erase(cache[c]);
        cache[c] = li.end();
    }
    int firstUniqChar(string s) {
        for ( auto x : s) {
            if (cache.find(x) != cache.end() && cache[x] != li.end()) {
                remove_ele(x);
            } else {
                add_ele(x);
            }
        }
        char result = li.front();
        cout<<"result:"<<"."<<result<<"."<<endl;
        if (result == ' ') {
            return -1;
        }
        for (int i=0;i<s.size();++i) {
            if (s[i] == result) {
                return i;
            }
        }
        return -1;
    }
};