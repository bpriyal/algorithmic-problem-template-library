class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> cache;
        cache['I'] = 1;
        cache['V'] = 5;
        cache['X'] = 10;
        cache['L'] = 50;
        cache['C'] = 100;
        cache['D'] = 500;
        cache['M'] = 1000;
        
        int size = s.size();
        int result = 0;
        for(int i = size-1;i >= 0;--i) {
            if (i == size -1) {
                result += cache[s[i]]; 
            } else {
                if (cache[s[i]] >= cache[s[i+1]]) {
                    result += cache[s[i]];
                } else {
                    result -= cache[s[i]];
                }
            }            
        }
        return result;
    }
};