class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majele;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                majele = num;
                count = 1;
            } else {
                if (num == majele) {
                    ++count;
                } else {
                    --count;
                }
            }
        }
        return majele;
    }
};