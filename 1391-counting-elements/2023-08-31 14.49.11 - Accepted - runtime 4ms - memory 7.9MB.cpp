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
            } else if (arr[i] == arr[i - 1] + 1) {
                result += runLength;
                runLength = 1;
            } else {
                runLength = 1;
            }
        }
        return result;
    }
};

// 0 1 2 2 4 5 6 9
//   1 2  