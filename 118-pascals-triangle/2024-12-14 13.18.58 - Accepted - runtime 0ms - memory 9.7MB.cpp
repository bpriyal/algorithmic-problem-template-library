class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows >= 1) result.emplace_back(vector<int>{1});
        if (numRows >= 2) result.emplace_back(vector<int>{1, 1});
        for (int i = 3; i <= numRows; ++i) {
            vector<int> temp(i, 1);
            for (int j = 1; j < i - 1; ++j)
                temp[j] = result[i - 2][j - 1] + result[i - 2][j];
            result.emplace_back(temp);
        }
        return result;
    }
};