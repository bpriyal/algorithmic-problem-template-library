class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> result;

        sort(nums.begin(), nums.end());

        for (int query : queries) {
            int answer = 0;
            for (int num : nums) {
                query -= num;
                if (query < 0) break;
                ++answer;
            }
            result.push_back(answer);
        }

        return result;
    }
};