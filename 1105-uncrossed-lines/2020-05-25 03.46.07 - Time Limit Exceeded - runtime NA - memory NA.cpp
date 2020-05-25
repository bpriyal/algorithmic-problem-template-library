class Solution {
public:
    int sizea,sizeb;
    
    int util(const vector<int> &A,const vector<int> &B,int a,int b) {
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
    }
};