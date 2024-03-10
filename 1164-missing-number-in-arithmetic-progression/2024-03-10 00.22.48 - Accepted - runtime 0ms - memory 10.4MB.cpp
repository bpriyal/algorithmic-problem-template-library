class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int difference = (arr.back() - arr.front()) / n;
        int expected = arr.front();
        for (const auto& element : arr) {
            if (element != expected) return expected;
            expected += difference;
        }
        return expected;
    }
};