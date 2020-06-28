class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int size = nums.size();
        int sum = 0;
        sort(nums.begin(),nums.end());
        int i,j;
        for (i = 0;i<size;++i) {
            int min = nums[i];
            if (2*min <= target) {
                for(j = i;j<size;++j) {
                    if (min + nums[j] > target) break;
                }
                sum += static_cast<int>(pow(2,j-1-i))%static_cast<int>(pow(10,9)+7);
            } else {
                cout<<i<<endl;
                break;
            }
        }
        return sum;
    }
};