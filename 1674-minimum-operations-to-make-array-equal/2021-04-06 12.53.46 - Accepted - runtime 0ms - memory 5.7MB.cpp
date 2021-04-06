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
