class Solution {
public:
    string getSmallestString(int n, int k) {
        string result;
        while (n > 0) {
            if (n*26-k >= 26) {
                result += 'a';
                --k;
            } else {
                int temp = 26-(n*26-k);
                result += ('a'+temp-1);
                k -= temp;
            }
            --n;
        }
        return result;
    }
};