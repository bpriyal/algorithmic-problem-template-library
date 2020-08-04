class Solution {
    bool util(int num) {
        if (num == 0) return false;
        while (num != 1) {
            if (num%4 != 0) {
                return false;
            }
            num /= 4;
        }
        return true;
    }
public:
    bool isPowerOfFour(int num) {
        /* return util(num); Method 1 */
        if (num && !(num & (num-1))) {
            int count = 0;
            while(num != 0) {
                ++count;
                num = num >> 1;
            }
            //cout<<count<<endl;
            if (count%2 != 0) {
                return true;
            } 
            return false;
        }
        return false;
    }
};