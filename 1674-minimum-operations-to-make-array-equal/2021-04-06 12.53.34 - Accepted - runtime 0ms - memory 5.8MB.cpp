class Solution {
public:
    int minOperations(int n) {
        int ref;
        if (n%2 == 0) {
            ref = ((2*(n/2)+1)+(2*(n/2-1)+1))/2;
        } else {
            ref = 2*(n/2)+1;
        }
        
        int result = 0;
        for(int i = 0;i < n/2;++i) {
            result += ref-(2*i+1);            
        }
        
        return result;
    }
};
/*
[0,1,2,3,4,5]
[1,3,5,7,9,11]
6+4+2
5+3+1
*/