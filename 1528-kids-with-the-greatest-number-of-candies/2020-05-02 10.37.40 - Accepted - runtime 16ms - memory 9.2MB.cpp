class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int max=candies[0];
        for (auto x:candies) {
            if ( x > max) {
                max = x;
            }
        }
        for (auto x:candies) {
            if ( x+extraCandies >= max) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};