class Solution {
    int sumOfEven(const vector<int>& nums) {
        int sum = 0;
        
        for (int num : nums) {
            sum += num % 2? 0 : num;
        }
        return sum;
    }
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int size = nums.size();
        vector<int> result;
        
        int init = sumOfEven(nums);
        
        for (auto query : queries) {
            int sum = result.empty()? init : result.back();
            
            if (nums[query[1]] % 2 == 0) {
                sum -= nums[query[1]];
            }
            
            nums[query[1]] += query[0];
            
            if (nums[query[1]] % 2 == 0) {
                sum += nums[query[1]];
            }
            
            result.push_back(sum);
        }
        
        return result;
    }
};