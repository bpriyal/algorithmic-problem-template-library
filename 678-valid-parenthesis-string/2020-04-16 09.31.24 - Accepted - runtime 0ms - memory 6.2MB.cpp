class Solution {
public:
    bool checkValidString(string s) {
        if (s.size()==0) return true;
        int l=0,h=0;
        for (int i=0;i<s.size();++i) {
            if (s[i]=='(') {
                ++l;
                ++h;
            } else if (s[i]==')') {
                --h;
                if (l>0) --l;
            } else if (s[i]=='*') {
                if(l>0) --l;
                ++h;
            }
            if (h<0) return false;
        }
        if (l==0) return true;
        return false;
    }
}; 