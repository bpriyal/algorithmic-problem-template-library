class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_map<char,int> cache;
        int size = s.size();
        vector<char> li = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        for(char c:li) {
            ++cache[c];
        }
        
        int counter = 0;
        for(int i = 0;i < size/2;++i) {
            if (cache[s[i]]) {
                ++counter;
            }
        }
        
        for(int i = size/2;i < size;++i) {
            if (cache[s[i]]) {
                --counter;
            }
        }
        
        return counter == 0;
    }
};