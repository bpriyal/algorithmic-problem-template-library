class Solution {
public:
    bool confusingNumber(int n) {
        unordered_map<int, int> validCache = { {0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6} };
        unordered_set<int> invalidCache = { 2, 3, 4, 5, 7 };

        int rotatedNumber = 0;
        int originalNumber = n;
        while (originalNumber > 0) {
            int digit = originalNumber % 10;
            if (invalidCache.count(digit)) return false;
            rotatedNumber = rotatedNumber * 10 + validCache[digit];
            originalNumber /= 10;
        }

        return n != rotatedNumber;
    }
};