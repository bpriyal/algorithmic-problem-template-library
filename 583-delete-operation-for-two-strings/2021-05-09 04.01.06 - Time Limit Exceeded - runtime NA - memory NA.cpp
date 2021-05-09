class Solution {
    int sizea,sizeb;
    int util(const string &a,const string &b,int i,int j) {
        if (i < 0 || j < 0) {
            return 0;
        }
        
        if (a[i] == b[j]) {
            return util(a,b,i-1,j-1) + 1;
        } else {
            return max(util(a,b,i-1,j),util(a,b,i,j-1));
        }
    }
public:
    int minDistance(string a, string b) {
        int sizea = a.size();
        int sizeb = b.size();
        
        return sizea+sizeb-2*util(a,b,sizea-1,sizeb-1);
    }
};