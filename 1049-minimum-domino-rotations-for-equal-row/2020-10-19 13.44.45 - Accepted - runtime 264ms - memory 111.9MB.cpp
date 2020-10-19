class Solution {
    int util(vector<int>& A, vector<int>& B,int key) {
        //cout<<key<<endl;
        int count = 0;
        for(int i = 0;i<A.size();++i) {
            if (A[i] != key && B[i] != key) {
                return -1;
            } else if (A[i] != key && B[i] == key){
                ++count;
            }
        }
        return count;
    }
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> freqA(6,0),freqB(6,0);
        for(int i = 0;i < A.size();++i) {
            ++freqA[A[i]-1];
            ++freqB[B[i]-1];
        }
        int maxa = freqA[0];
        int maxb = freqB[0];
        int a = 1,b = 1;
        for(int i = 1;i<6;++i) {
            if (maxa < freqA[i]) {
                maxa = freqA[i];
                a = i+1;
            }
            if (maxb < freqB[i]) {
                maxb = freqB[i];
                b = i+1;
            }
        }
        //cout<<maxb<<endl;
        return maxa > maxb ? util(A,B,a):util(B,A,b);
    }
};