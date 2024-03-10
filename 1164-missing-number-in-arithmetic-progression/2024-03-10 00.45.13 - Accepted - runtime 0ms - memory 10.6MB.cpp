class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int difference = (arr.back() - arr.front()) / n;
        int expected = arr.front();
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // All indexes upto `mid` are correct, missing number is on right
            if (arr[mid] == arr.front() + mid * difference) l = mid + 1;
            else r = mid;
        }
        return arr.front() + l * difference;
    }
};