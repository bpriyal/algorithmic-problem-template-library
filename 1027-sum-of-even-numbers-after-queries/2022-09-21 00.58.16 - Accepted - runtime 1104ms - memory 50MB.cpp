class Solution {
    int sumOfEven(const vector<int>& nums) {
        int sum = 0;
        
        for (int num : nums) {
            // cout<<num<<"\t";
            sum += num % 2? 0 : num;
        }
        // cout<<endl;
        return sum;
    }
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int size = nums.size();
        vector<int> result;
        
        for (auto query : queries) {
            nums[query[1]] += query[0];
            
            result.push_back(sumOfEven(nums));
        }
        
        return result;
    }
};