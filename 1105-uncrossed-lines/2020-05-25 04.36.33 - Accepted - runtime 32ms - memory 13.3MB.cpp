class Solution {
public:
    int sizea,sizeb;
    vector<vector<int>> result;
    
    /*int util(const vector<int> &A,const vector<int> &B,int a,int b) {
        if (a >= sizea || b >= sizeb) return 0;
        for (int j = b;j< sizeb;++j) {
            if (A[a] == B[j]) {
                return max(1+util(A,B,a+1,j+1),util(A,B,a+1,b));
            }
        }
        return util(A,B,a+1,b);
    }
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        sizea = A.size();
        sizeb = B.size();
        return util(A,B,0,0);
    }*/
    
    //solution 2 
    
    int util(const vector<int> &A,const vector<int> &B,int a,int b) {
        if (a >= sizea || b >= sizeb) return 0;
        if (result[a][b] != -1) {
            return result[a][b];
        }
        int maxsofar = 0;
        maxsofar = max(util(A,B,a+1,b),util(A,B,a,b+1));
        if (A[a] == B[b]) {
            maxsofar = max(1+util(A,B,a+1,b+1),maxsofar);
        }
        result[a][b] = maxsofar;
        return result[a][b];
    }
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        sizea = A.size();
        sizeb = B.size();
        result.resize(sizea+1);
        for (int i=0;i<sizea+1;++i) {
            result[i].resize(sizeb+1,-1);
        }
        return util(A,B,0,0);
    }
};