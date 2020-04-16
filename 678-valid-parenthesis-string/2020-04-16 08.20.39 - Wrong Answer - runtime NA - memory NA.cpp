class Solution {
public:
    bool checkValidString(string s) {
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
        /*if (bracket.size() <= star_count) {
            return true;
        }*/
        return false;
    }
}; 