class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int rows = words.size();
        int cols = words[0].size();
        int k = max(rows, cols);
        for (int i = 0; i < rows && i < k; ++i) {
            for (int j = 0; j < cols && j < k; ++j) {
                if (words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};