class Solution {
public:
    int countElements(vector<int>& arr) {
        int size = arr.size();
        sort(arr.begin(), arr.end());
        int runLength = 0, result = 0;
        for (int i = 0; i < size; ++i) {
            if (i == 0 || arr[i] == arr[i - 1]) {
                ++runLength;
                continue;
            }
            if (arr[i] == arr[i - 1] + 1) {
                result += runLength;
                runLength = 1;
            }
        }
        return result;
    }
};