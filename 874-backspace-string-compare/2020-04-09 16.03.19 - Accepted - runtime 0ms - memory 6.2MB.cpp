#include <string.h>
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        size_t n;
        while((n=S.find('#'))!=string::npos){
            if(n!=0){
                S.erase(n-1,2);
            } else{
                S.erase(n,1);
            }
        }
        while((n=T.find('#'))!=string::npos){
            if(n!=0){
                T.erase(n-1,2);
            } else{
                T.erase(n,1);
            }
        }
        cout<<S<<endl;
        cout<<T<<endl;
        if(S==T){
            return true;
        }
        return false;
    }
};