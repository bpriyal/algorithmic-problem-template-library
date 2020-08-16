class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int size = arr.size();
        if (size < 3) {
            return false;
        }
        int count = 0;
        for(int i = 0;i<size;++i) {
            if (count == 3) {
                return true;
            }
            if (arr[i] % 2 == 0) {
                count = 0;
            } else {
                ++count;
            }
        }
        if (count == 3) {
            return true;
        }
        return false;
    }
};