class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> run = arrays[0];
        vector<int> temp;
        for (int i = 1; i < arrays.size(); ++i) {
            temp = {};
            int j = 0, k = 0;
            while (j < run.size() && k < arrays[i].size()) {
                if (run[j] == arrays[i][k]) {
                    temp.emplace_back(run[j]);
                    ++j;
                    ++k;
                } else if (run[j] > arrays[i][k]) ++k;
                else ++j;
            }
            run = temp;
        }
        return run;
    }
};
// N = no of sub arrays
// L = size of largest sub array
// Time = O(N * L)
// Space = O(L)