class Solution {
    vector<vector<char>> reversiblePairs = {{'1', '1'}, {'0', '0'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};

    vector<string> util(int n, int requiredLength) {
        if (n == 0) return {""};
        if (n == 1) return {"0", "1", "8"};

        vector<string> temp = util(n - 2, requiredLength);

        vector<string> result;
        for (auto& pair : reversiblePairs) {
            if (pair[0] != '0' || requiredLength != n) {
                for (auto num : temp) {
                    result.emplace_back(pair[0] + num + pair[1]);
                }
            }
        }
        return result;
    }
public:
    vector<string> findStrobogrammatic(int n) {
        return util(n, n);
    }
};