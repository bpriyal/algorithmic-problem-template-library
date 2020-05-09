class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0) return false;
        int i;
        for (i=1;i*i<=num;++i) {
            if (i*i == num) {
                return true;
            }
        }
        return false;
    }
};