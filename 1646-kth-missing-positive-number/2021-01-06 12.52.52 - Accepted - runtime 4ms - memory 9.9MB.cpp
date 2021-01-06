class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int size = arr.size();
        int idx = 0;
        int num = 1;
        while (idx < size) {
            if (num == arr[idx]) {
                ++idx;
            } else {
                --k;
            }
            if (k == 0) {
                return num;
            }
            ++num;
        }
        return num + k - 1;
    }
};