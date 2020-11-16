class Solution {
public:
    int longestMountain(vector<int>& A) {
        int start = -1,end = 0,_max = 0;
        int size = A.size();
        int i = 0;
        bool flag = false;
        while(i < size-1) {
            if (!flag) {
                if (A[i] < A[i+1]) {
                    if (start == -1) {
                        //printf("%d\n",i);
                        start = i;
                    }
                    ++i;
                    continue;
                } else if (A[i] > A[i+1]) {
                    if (start != -1) {
                        //cout<<"hereeee"<<endl;
                        flag = true;
                    }
                    ++i;
                } else {
                    ++i;
                    start = -1;
                }
            } else {
                if (A[i] > A[i+1]) {
                    ++i;
                    continue;
                } else {
                    _max = max(_max,i-start+1);
                    //printf("%d||%d||%d\n",_max,i,start);
                    start = i;
                    //printf("%d\n",start);
                    flag = false;
                }
            }
        }
        if(flag == true) {
            _max = max(_max,i-start+1);
            //printf("%d|||%d|||%d\n",_max,i,start);
        }
        return _max;
    }
};