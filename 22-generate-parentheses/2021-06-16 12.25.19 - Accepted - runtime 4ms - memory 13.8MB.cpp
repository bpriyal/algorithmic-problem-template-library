class Solution {
    vector<string> result;
    
    void util(int open,int close,int curr,string run) {
        if (open == 0 && close == 0) {
            result.push_back(run);
        }
        
        // add open
        if (open != 0) {
            util(open-1,close,curr+1,run+"(");
        }
        
        // add close
        if (curr != 0) {
            util(open,close-1,curr-1,run+")");
        }
    } 
    
public:
    vector<string> generateParenthesis(int n) {
        string temp = "";
        util(n,n,0,temp);
        return result;
    }
};