class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int result = 0; // the actual sum
        int difference = INT_MAX;
        
        sort(nums.begin(), nums.end());
                
        for (int i = 0; i < size - 2; ++i) {
            int j = i + 1;
            int k = size - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (abs(sum - target) < difference) {
                    cout<<nums[i]<<", "<<nums[j]<<", "<<nums[k]<<endl;
                    cout<<"sum: "<<sum<<endl;
                    result = sum;
                    difference = abs(sum - target);
                    cout<<"diff: "<<difference<<endl;
                }
                
                if (sum == target) return result;
                else if (sum < target) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        
        return result;
    }
};