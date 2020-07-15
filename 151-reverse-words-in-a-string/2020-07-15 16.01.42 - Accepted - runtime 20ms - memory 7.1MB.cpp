class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return s;
        reverse(s.begin(),s.end());
        int i =0;
        int j =0;
        //cout<<s<<endl;
        while(i<s.size()) {
            if (s[i] != ' ') {
                j = i;
                while(j < s.size() && s[j]!=' ') {
                    ++j;
                }
                for(int k=0;k<(j-i)/2;++k) {
                    char temp = s[i+k];
                    s[i+k]=s[j-1-k];
                    s[j-1-k] = temp;
                }
                ++j;
                while(j<s.size() && s[j]==' ') {
                    s.erase(j,1);
                }
                if (j == s.size()) {
                    s.erase(j-1,1);
                }
                i = j;
            } else {
                //cout<<i<<endl;
                s.erase(i,1);
            }
        }
        return s;
    }
};