class Solution {
    vector<vector<char>> reversiblePairs = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'9', '6'}, {'8', '8'}};
public:
    bool isStrobogrammatic(string num) {
        int size = num.size();
        int p1 = 0, p2 = size - 1;

        while (p1 <= p2) {
            if (std::find(reversiblePairs.begin(), reversiblePairs.end(), vector<char>({num[p1], num[p2]})) == reversiblePairs.end()) {
                return false;
            }
            ++p1;
            --p2;
        }
        return true;
    }
};