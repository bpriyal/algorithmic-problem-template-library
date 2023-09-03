class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int rows = words.size();
        int cols = words[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};