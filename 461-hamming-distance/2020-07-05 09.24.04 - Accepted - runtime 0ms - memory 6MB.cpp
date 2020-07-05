class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while(x != 0 || y != 0) {
            if ((x%2 == 0 && y%2 != 0) || (x%2 != 0 && y%2 == 0)) {
                ++count;
            }
            x = x>>1;
            y = y>>1;
        }
        return count;
    }
};