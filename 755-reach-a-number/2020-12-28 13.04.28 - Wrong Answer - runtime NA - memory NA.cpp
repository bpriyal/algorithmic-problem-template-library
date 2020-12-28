class Solution {
public:
    int reachNumber(int target) {
        int pos = 0;
        int n = 0;
        
        while (pos < target) {
            ++n;
            pos += n;
        }
        
        while((pos-target)%2 != 0) {
            ++n;
            pos += n;
        }
        
        return n;
    }
};