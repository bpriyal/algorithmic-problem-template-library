class Solution {
public:
    int longestPalindrome(string s) {
        int sizeOfCache = 'z'-'A'+1;
        vector<int> cache(sizeOfCache,0);
        int size = s.size();
        for(int i = 0;i<size;++i) {
            cout<<s[i]<<endl;
            ++cache[s[i]-'A'];
        }
        cout<<"here"<<endl;
        int result = 0;
        bool oddEncountered = false;
        for(int i = 0;i<sizeOfCache;++i) {
            if (cache[i] % 2 == 0) {
                result += cache[i];
            } else {
                oddEncountered = true;
                result += cache[i]-1;
            }
        }
        return oddEncountered? result + 1 : result;
    }
};