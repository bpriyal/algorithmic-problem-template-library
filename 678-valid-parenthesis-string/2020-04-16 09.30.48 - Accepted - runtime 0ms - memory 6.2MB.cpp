class Solution {
public:
    /*bool checkValidString(string s) {
        if (s.size()==0) return true;
        stack<char> bracket;
        int star_count=0;
        
        for(int i=0;i<s.size();++i){
            if (s[i]=='(') {
                bracket.push(s[i]);
            } else if (s[i]==')') {
                if (bracket.empty()) {
                    if (!star_count) {
                        return false;
                    } else {
                        --star_count;
                    }
                } else {
                   bracket.pop(); 
                }
            } else if (s[i]=='*'){
                ++star_count;
            }
        }
        if (bracket.size() == 0) return true;
        if (bracket.size() <= star_count) {
            cout<<bracket.size()<<endl;
            cout<<star_count<<endl;
            return true;
        }
        return false;
    }*/
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