class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(),nums.end(),[](const int &a,const int &b) {
            string x = to_string(a);
            string y = to_string(b);
            return (x+y).compare(y+x) > 0;
        });
        if (nums[0]==0) {
            return "0";
        }
        string result = "";
        for(int n:nums) {
            result += to_string(n);
        }
        return result;
    }
};