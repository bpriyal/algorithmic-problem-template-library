class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::optional<int> candidate1, candidate2;
        int count1 = 0, count2 = 0;
        for (int num : nums) {
            if (candidate1 && *candidate1 == num) ++count1;
            else if (candidate2 && *candidate2 == num) ++count2;
            else if (count1 == 0) {
                candidate1 = num;
                ++count1;
            }
            else if (count2 == 0) {
                candidate2 = num;
                ++count2;
            }
            else {
                --count1;
                --count2;
            }
        }

        count1 = count2 = 0;
        for (int num : nums) {
            if (candidate1 && *candidate1 == num) ++count1;
            else if (candidate2 && *candidate2 == num) ++count2;
        }
        vector<int> result;
        if (count1 > nums.size() / 3) result.emplace_back(*candidate1);
        if (count2 > nums.size() / 3) result.emplace_back(*candidate2);
        return result;
    }
};