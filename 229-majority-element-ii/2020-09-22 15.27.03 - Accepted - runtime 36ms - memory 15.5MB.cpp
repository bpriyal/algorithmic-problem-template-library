class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
         
        if (nums.size() == 0) {
            return result;
        }
         
        if (nums.size() == 1) {
            result.push_back(nums[0]);
            return result;
        }
         
        int candidate1 = nums[0];
        int candidate2 = 0;
         
        int count1 = 1;
        int count2 = 0;
         
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (candidate1 == num) {
                count1++;
            } else if (candidate2 == num) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
         
        count1 = 0;
        count2 = 0;
         
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            }
        }
         
        if (count1 > nums.size() / 3) {
            result.push_back(candidate1);
        }
         
        if (count2 > nums.size() / 3) {
            result.push_back(candidate2);
        }
         
        return result;
    }
};