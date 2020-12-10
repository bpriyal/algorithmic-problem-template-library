class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int size = arr.size();
        if (size < 3) {
            return false;
        }
        bool startDec = false;
        int changePos = -1;
        for(int i = 1;i < size;++i) {
            if (!startDec) {
                if (arr[i] == arr[i-1]) {
                    return false;
                }
                if (arr[i] < arr[i-1]) {
                    startDec = true;
                    changePos = i;
                }
            } else {
                if (arr[i] == arr[i-1]) {
                    return false;
                }
                if (arr[i] > arr[i-1]) {
                    return false;
                }
            }
        }
        return changePos > 1;
    }
};